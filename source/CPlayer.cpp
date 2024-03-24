#include "CPlayer.h"

#include <iostream>

CPlayer::CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy)
{
    mName = name;
    mLevelOfMotivation = levelOfMotivation;
    mSuccess = success;
    mYearOfStudy = yearOfStudy;
}

void CPlayer::setMotivation(int levelOfMotivation)
{
    mLevelOfMotivation = levelOfMotivation;

    // make sure motivation doesn't go below 0
    if (mLevelOfMotivation < 0)
    {
        mLevelOfMotivation = 0;
    }
}

CPlayer::CPlayer(std::string name)
{
    mName = name;
}

CPlayer::~CPlayer()
{
    std::cout << "Destroying player: " << mName << std::endl;
}

void CPlayer::setCurrentSpace(std::shared_ptr<CSpace> space)
{
    mCurrentSpace = space;
}

std::shared_ptr<CSpace> CPlayer::getCurrentSpace()
{
    return mCurrentSpace;
}

// cout operator overload
std::ostream& operator<<(std::ostream& os, const CPlayer& player)
{
    // print out the player's new success and motivation:
    os << player.mName << "'s motivation is " << player.mLevelOfMotivation << " and success is "
       << player.mSuccess << std::endl
       << std::endl;

    return os;
}

std::vector<std::shared_ptr<CAssessment>> CPlayer::getCompletedAssessments(int year)
{
    std::vector<std::shared_ptr<CAssessment>> assessmentsForYear;

    for (const auto& assessment : mAssessments)
    {
        if (assessment->getYear() == year)
        {
            assessmentsForYear.push_back(assessment);
        }
    }

    return assessmentsForYear;
}
