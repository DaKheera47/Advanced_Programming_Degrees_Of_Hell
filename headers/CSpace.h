#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "CPlayer.h"  // Make sure this file exists and defines CPlayer

class CSpace
{
protected:
    int type;
    std::string name;
    int motivationalCost;
    int achievement;
    int yearOfStudy;

public:
    CSpace(const std::string& nameValue, int typeValue, int motivationalCostValue,
           int achievementValue, int yearOfStudyValue)
    {
        name = nameValue;
        type = typeValue;
        motivationalCost = motivationalCostValue;
        achievement = achievementValue;
        yearOfStudy = yearOfStudyValue;
    }

    virtual ~CSpace() {}  // Virtual destructor for safe polymorphic use

    // Pure virtual function making CSpace abstract
    virtual void handlePlayerInteraction(std::unique_ptr<CPlayer>& player) = 0;

    virtual std::string getName() { return name; };
};
