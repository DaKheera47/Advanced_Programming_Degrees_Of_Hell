#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy)
{
    mName = name;
    mLevelOfMotivation = levelOfMotivation;
    mSuccess = success;
    mYearOfStudy = yearOfStudy;
}

CPlayer::~CPlayer()
{
    std::cout << "Destroying player: " << mName << std::endl;
}

std::string CPlayer::getName()
{
    return mName;
}

// cout operator overload
std::ostream &operator<<(std::ostream &os, const CPlayer &player)
{
    os << "Player: " << player.mName << " Motivation: " << player.mLevelOfMotivation << " Success: " << player.mSuccess << " Year: " << player.mYearOfStudy;
    return os;
}
