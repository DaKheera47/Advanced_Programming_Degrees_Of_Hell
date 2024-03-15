#pragma once

#include <iostream>

class CPlayer
{
private:
    std::string mName;
    int mLevelOfMotivation;
    int mSuccess;
    int mYearOfStudy;

public:
    CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy);
    ~CPlayer();

    // cout operator overload
    friend std::ostream &operator<<(std::ostream &os, const CPlayer &player);

    std::string getName();
};
