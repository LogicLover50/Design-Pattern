#ifndef MULTIPLICATIVEMODIFIER_H
#define MULTIPLICATIVEMODIFIER_H

#include "IModifier.h"

class MultiplicativeModifier : public IModifier
{
private:
    float multiplier;
    std::string name;

public:
    MultiplicativeModifier(std::string name, float multiplier) 
        : name(name), multiplier(multiplier) {}

    int apply(int currentScore) const override
    {
        return static_cast<int>(currentScore * multiplier);
    }

    std::string getName() const override
    {
        return name;
    }
};

#endif