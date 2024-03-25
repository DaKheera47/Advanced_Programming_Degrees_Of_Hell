#include "CPlayer.h"

#include <iostream>

#include "CUtils.h"

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
    // nothing to do
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

CAssessmentVector CPlayer::GetCompletedAssessments(int year)
{
    CAssessmentVector assessmentsForYear;

    for (const auto& pAssessment : mCompletedAssessments)
    {
        if (pAssessment->GetYear() == year)
        {
            assessmentsForYear.push_back(pAssessment);
        }
    }

    return assessmentsForYear;
}

bool CPlayer::ApplyForMC()
{
    return true;
}

void CPlayer::DeferAssessment(std::shared_ptr<CAssessment>& pAssessment)
{
    // make sure there is logic to apply for MCs
    // likely to be implemented later
    if (!ApplyForMC())
    {
        // nothing happens if rejected
        return;
    }

    // Defer the assessment
    mDeferredAssessments.push_back(pAssessment);

    // remove all the success of theis assessment from the player
    SetSuccess(mSuccess - pAssessment->GetSuccess());

    // add all the motivation back to the player
    mMotivation += pAssessment->GetMotivationCost();

    // print out the message to show
    std::cout << mName << " defers " << pAssessment->GetName() << " for "
              << pAssessment->GetMotivationCost() << " motivation and loses "
              << pAssessment->GetSuccess() << " success" << std::endl;
}

bool CPlayer::DeferAssessmentsToGetMotivation(int targetMotivation)
{
    // Sort assessments based on their motivation cost (ascending order)
    std::sort(mCompletedAssessments.begin(), mCompletedAssessments.end(),
              CUtils::compareAssessments);

    // Defer assessments until the player has enough motivation
    for (auto& pAssessment : mCompletedAssessments)
    {
        if (mMotivation >= targetMotivation)
        {
            return true;
        }

        DeferAssessment(pAssessment);
    }

    return mMotivation >= targetMotivation;
}

void CPlayer::ResubmitDeferredAssessment()
{
    // Sort deferred assessments based on their motivation cost (ascending order)
    std::sort(mDeferredAssessments.begin(), mDeferredAssessments.end(), CUtils::compareAssessments);

    for (auto& pAssessment : mDeferredAssessments)
    {
        if (pAssessment == nullptr)
        {
            continue;
        }

        if (mMotivation >= pAssessment->GetMotivationCost())
        {
            // Add the assessment to the player's completed assessments
            mCompletedAssessments.push_back(pAssessment);

            // Deduct the motivation cost from the player
            mMotivation -= pAssessment->GetMotivationCost();

            // Add the success of the assessment to the player
            SetSuccess(mSuccess + pAssessment->GetSuccess());

            // output message
            std::cout << mName << " submits deferred assessment " << pAssessment->GetName()
                      << " for " << pAssessment->GetMotivationCost() << " motivation and gains "
                      << pAssessment->GetSuccess() << " success" << std::endl;
        }
    }
}

void CPlayer::HandleDeferredAssessments()
{
    ResubmitDeferredAssessment();

    // remove all the assessments in deferred assessments and mcompleted assessments from mDeferred
    // assesssments
    for (const auto& pAssessment : mCompletedAssessments)
    {
        auto it = std::find(mDeferredAssessments.begin(), mDeferredAssessments.end(), pAssessment);

        if (it != mDeferredAssessments.end())
        {
            mDeferredAssessments.erase(it);
        }
    }

    bool canDeferMore = DeferAssessmentsToGetMotivation(0);

    if (!canDeferMore)
    {
        std::cout << mName << " can't defer any more assessments." << std::endl;

        SetDroppedOut(true);
    }

    // remove this player from the completed by list of assessments which are deferred
    for (const auto& pAssessment : mDeferredAssessments)
    {
        auto it =
            std::find(mCompletedAssessments.begin(), mCompletedAssessments.end(), pAssessment);

        if (it != mCompletedAssessments.end())
        {
            mCompletedAssessments.erase(it);
        }
    }
}
