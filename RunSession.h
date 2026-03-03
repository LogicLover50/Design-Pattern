#ifndef RUNSESSION_H
#define RUNSESSION_H

#include <vector>
#include <string>
// #include "IModifier.h"

class RunSession 
{
private:
    int currentRound;
    int totalScore;
    bool isRunActive;
    // std::vector<IModifier*> activeModifiers;

public:
    RunSession();
    ~RunSession();

    void startRun();
    void playHand();
    void enterShop();
    void endRun();
    
    // void addModifier(IModifier* newMod);
};

#endif