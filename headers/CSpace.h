#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "CPlayer.h" // Make sure this file exists and defines CPlayer

class CSpace
{
protected:
    std::string name;
    int type;
    int motivationalCost;
    int achievement;
    int yearOfStudy;

public:
    CSpace(const std::string &nameValue, int typeValue, int motivationalCostValue, int achievementValue, int yearOfStudyValue)
    {
        name = nameValue;
        type = typeValue;
        motivationalCost = motivationalCostValue;
        achievement = achievementValue;
        yearOfStudy = yearOfStudyValue;
    }

    virtual ~CSpace() {} // Virtual destructor for safe polymorphic use

    // Pure virtual function making CSpace abstract
    virtual void handlePlayerInteraction(std::unique_ptr<CPlayer> &player) = 0;

    virtual std::string getName() { return name; };
};
