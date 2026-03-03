#include "RunSession.h"
#include <iostream>
using namespace std;

RunSession::RunSession() : currentRound(1), totalScore(0), isRunActive(false) {}

void RunSession::startRun() 
{
    isRunActive = true;
    cout << "--- Starting New Run ---" << endl;
    
    while (isRunActive && currentRound <= 3) 
    {
        cout << "\nROUND " << currentRound << endl;
        playHand();
        enterShop();
        currentRound++;
    }
    
    endRun();
}

void RunSession::playHand() 
{
    int baseScore = 100;
    int finalScore = baseScore;

    cout << "Playing hand... Base Score: " << baseScore << endl;

    for (auto mod : activeModifiers) 
    {
        finalScore = mod->apply(finalScore); 
    }

    totalScore += finalScore;
    cout << "Final Hand Score: " << finalScore << endl;
    cout << "Total Run Score: " << totalScore << endl;
}

void RunSession::enterShop() 
{
    cout << "[Shop] Would you like to buy a Modifier? (y/n): ";
}

void RunSession::endRun() 
{
    isRunActive = false;
    cout << "\n--- Run Over ---" << endl;
    cout << "Final Total Score: " << totalScore << endl;
}

void RunSession::addModifier(IModifier* newMod) 
{
    activeModifiers.push_back(newMod);
}

RunSession::~RunSession()
{
    for (auto mod : activeModifiers)
    {
        delete mod;
    }
    activeModifiers.clear();
}