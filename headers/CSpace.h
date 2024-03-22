#pragma once

#include <iostream>
#include <memory>
#include <string>

// #include "CPlayer.h"
#include "./enums/ESpaceType.h"

class CSpace
{
protected:
    ESpaceType mType;
    std::string mName;
    int mMotivationalCost;
    int mSuccess;
    int mYear;

public:
    CSpace(){};
    CSpace(ESpaceType type) { mType = type; };
    CSpace(const std::string& nameValue, ESpaceType typeValue, int motivationalCostValue,
           int achievementValue, int yearOfStudyValue)
    {
        mName = nameValue;
        mType = typeValue;
        mMotivationalCost = motivationalCostValue;
        mSuccess = achievementValue;
        mYear = yearOfStudyValue;
    }

    virtual ~CSpace() {}  // Virtual destructor for safe polymorphic use

    // Pure virtual function making CSpace abstract
    // virtual void handlePlayerInteraction(std::unique_ptr<CPlayer>& player) = 0;

    // Virtual getters
    virtual ESpaceType getType() const { return mType; }
    virtual const std::string& getName() const { return mName; }
    virtual int getMotivationalCost() const { return mMotivationalCost; }
    virtual int getSuccess() const { return mSuccess; }
    virtual int getYear() const { return mYear; }

    // Virtual setters
    virtual void setType(ESpaceType newType) { mType = newType; }
    virtual void setName(const std::string& newName) { mName = newName; }
    virtual void setMotivationalCost(int newMotivationalCost)
    {
        mMotivationalCost = newMotivationalCost;
    }
    virtual void setSuccess(int newSuccess) { mSuccess = newSuccess; }
    virtual void setYear(int newYear) { mYear = newYear; }
};

using UniqSpaceVector = std::vector<std::unique_ptr<CSpace>>;
using UniqSpace = std::unique_ptr<CSpace>;
