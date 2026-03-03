#ifndef IMODIFIER_H
#define IMODIFIER_H

#include <string>

class IModifier 
{
public:
    virtual ~IModifier() {}

    virtual int apply(int currentScore) const = 0;

    virtual std::string getName() const = 0;
};

#endif