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

    // setters
    void setCurrentSpace(std::shared_ptr<CSpace> space);
    void setName(const std::string& name) { mName = name; }
    void setMotivation(int levelOfMotivation) { mLevelOfMotivation = levelOfMotivation; }
    void setSuccess(int success) { mSuccess = success; }
    void setYearOfStudy(int yearOfStudy) { mYearOfStudy = yearOfStudy; }

    // getters
    std::shared_ptr<CSpace> getCurrentSpace();
    std::string getName() const { return mName; }
    int getMotivation() const { return mLevelOfMotivation; }
    int getSuccess() const { return mSuccess; }
    int getYearOfStudy() const { return mYearOfStudy; }
};
