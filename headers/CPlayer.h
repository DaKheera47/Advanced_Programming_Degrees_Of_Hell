#pragma once

#include <iostream>

#include "CSpace.h"

class CPlayer
{
private:
    std::string mName;
    int mLevelOfMotivation = 1000;
    int mSuccess = 0;
    int mYearOfStudy = 1;

    std::shared_ptr<CSpace> mCurrentSpace;

public:
    CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy);
    CPlayer(std::string name);
    ~CPlayer();

    // cout operator overload
    friend std::ostream& operator<<(std::ostream& os, const CPlayer& player);

    std::string getName();
    std::shared_ptr<CSpace> getCurrentSpace();

    void setCurrentSpace(std::shared_ptr<CSpace> space);
};
