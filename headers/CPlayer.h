#pragma once

#include <iostream>

class CPlayer
{
private:
    std::string mName;
    int mLevelOfMotivation = 1000;
    int mSuccess = 0;
    int mYearOfStudy = 1;

public:
    CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy);
    CPlayer(std::string name);
    ~CPlayer();

    // cout operator overload
    friend std::ostream& operator<<(std::ostream& os, const CPlayer& player);

    std::string getName();
};
