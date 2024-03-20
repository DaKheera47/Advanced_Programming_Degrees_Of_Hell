#pragma once

#include <iostream>
#include <memory>
#include <string>

// #include "CPlayer.h"

class CSpace
{
protected:
    int type;
    std::string mName;
    int mMotivationalCost;
    int mSucess;
    int mYear;

public:
    CSpace(const std::string& nameValue, int typeValue, int motivationalCostValue,
           int achievementValue, int yearOfStudyValue)
    {
        mName = nameValue;
        type = typeValue;
        mMotivationalCost = motivationalCostValue;
        mSucess = achievementValue;
        mYear = yearOfStudyValue;
    }

    ~CSpace() {}  // destructor for safe polymorphic use

    // Pure virtual function making CSpace abstract

    std::string getName()
    {
        std::cout << mName << std::endl;
        return mName;
    };
};

using UniqSpaceVector = std::vector<std::unique_ptr<CSpace>>;
using UniqSpace = std::unique_ptr<CSpace>;
