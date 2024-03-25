#include "CPlayer.h"

#include <iostream>

CPlayer::CPlayer(std::string name, int motivation, int success, int yearOfStudy)
{
    mName = name;
    mMotivation = motivation;
    mSuccess = success;
    mYearOfStudy = yearOfStudy;
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

void CPlayer::SetSuccess(int success)
{
    mSuccess = success;

    // Ensure success is not negative
    if (mSuccess < 0)
    {
        mSuccess = 0;
    }
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
