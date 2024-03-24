#include "CPlayer.h"

#include <iostream>

CPlayer::CPlayer(std::string name, int motivation, int success, int yearOfStudy)
{
    mName = name;
    mMotivation = motivation;
    mSuccess = success;
    mYearOfStudy = yearOfStudy;
}

void CPlayer::SetMotivation(int motivation)
{
    mMotivation = motivation;

    // Make sure motivation doesn't go below 0
    if (mMotivation < 0)
    {
        mMotivation = 0;
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

void CPlayer::SetCurrentSpace(std::shared_ptr<CSpace> pSpace)
{
    mpCurrentSpace = pSpace;
}

std::shared_ptr<CSpace> CPlayer::GetCurrentSpace()
{
    return mpCurrentSpace;
}

// cout operator overload
std::ostream& operator<<(std::ostream& os, const CPlayer& player)
{
    // Print out the player's new success and motivation
    os << player.mName << "'s motivation is " << player.mMotivation << " and success is "
       << player.mSuccess << std::endl
       << std::endl;

    return os;
}

std::vector<std::shared_ptr<CAssessment>> CPlayer::GetCompletedAssessments(int year)
{
    std::vector<std::shared_ptr<CAssessment>> assessmentsForYear;

    for (const auto& pAssessment : mAssessments)
    {
        if (pAssessment->GetYear() == year)
        {
            assessmentsForYear.push_back(pAssessment);
        }
    }

    return assessmentsForYear;
}
