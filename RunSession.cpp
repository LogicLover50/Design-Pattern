#include "RunSession.h"
#include <iostream>
#using namespace std;

RunSession::RunSession() : currentRound(1), totalScore(0), isRunActive(false) {}

void RunSession::startRun() {
    isRunActive = true;
    std::cout << "--- Starting New Run ---" << std::endl;
    
    while (isRunActive && currentRound <= 3) {
        std::cout << "\nROUND " << currentRound << std::endl;
        playHand();
        enterShop();
        currentRound++;
    }
    
    endRun();
}

void RunSession::playHand() {
    int baseScore = 100; // Simplified for now
    int finalScore = baseScore;

    std::cout << "Playing hand... Base Score: " << baseScore << std::endl;

    // This is the "Decorator-like" behavior:
    // We loop through modifiers and let each one change the score.
    for (auto mod : activeModifiers) {
        finalScore = mod->apply(finalScore); 
    }

    totalScore += finalScore;
    std::cout << "Final Hand Score: " << finalScore << std::endl;
    std::cout << "Total Run Score: " << totalScore << std::endl;
}

void RunSession::enterShop() {
    std::cout << "[Shop] Would you like to buy a Modifier? (y/n): ";
    // Here is where you will eventually call your ModifierFactory
}

void RunSession::endRun() {
    isRunActive = false;
    std::cout << "\n--- Run Over ---" << std::endl;
    std::cout << "Final Total Score: " << totalScore << std::endl;
}

void RunSession::addModifier(IModifier* newMod) {
    activeModifiers.push_back(newMod);
}