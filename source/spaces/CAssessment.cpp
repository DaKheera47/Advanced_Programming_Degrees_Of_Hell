#include "../../headers/spaces/CAssessment.h"

#include <iostream>
#include <memory>
#include <set>

#include "../../headers/CDebugUtils.h"
#include "../../headers/CUtils.h"

CAssessment::~CAssessment()
{
    // clean up all players
    mCompletedBy.clear();
}

void CAssessment::PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    // Check if player has already completed the assessment
    for (const auto& weakPlayer : mCompletedBy)
    {
        auto sharedPlayer = weakPlayer.lock();

        // check if the player's getCompletedAssessments() has the assessment
        for (const auto& assess : sharedPlayer->GetCompletedAssessments())
        {
            if (sharedPlayer == player && assess == shared_from_this())
            {
                // message output
                std::cout << player->GetName() << " has already completed " << mName << std::endl;
                // Player has already completed this assessment, no further action is taken.
                return;
            }
        }
    }

    // Calculate the final success and motivational cost, accounting for shared efforts if
    // applicable
    int finalSuccess = mSuccess;
    int finalMotivationCost = mMotivationCost;

    if (mCompletedBy.size() >= 1)
    {
        int count = 0;

        // counting the number of helpers, excluding the player themselvess
        for (const auto& helper : mCompletedBy)
        {
            auto lockedHelper = helper.lock();

            if (lockedHelper && lockedHelper != player)
            {
                count++;
            }
        }

        finalSuccess /= count + 1;
        finalMotivationCost /= 2;
    }

    // Verify if the player has enough motivation to attempt this assessment
    if (player->GetMotivation() < finalMotivationCost)
    {
        std::cout << player->GetName() << " doesn't have the " << finalMotivationCost
                  << " motivation to complete " << mName << std::endl;

        // Insufficient motivation, player cannot attempt the assessment.
        return;
    }

    // Apply the assessment's effects to the player
    player->SetSuccess(player->GetSuccess() + finalSuccess);
    player->SetMotivation(player->GetMotivation() - finalMotivationCost);

    std::cout << player->GetName() << " completes " << mName << " for " << finalMotivationCost
              << " and achieves " << finalSuccess << std::endl;

    // Acknowledge contributions from other players, if any
    if (mCompletedBy.size() >= 1)
    {
        for (auto& helper : mCompletedBy)
        {
            auto lockedHelper = helper.lock();

            if (lockedHelper && lockedHelper != player)
            {
                std::cout << "\t..." << lockedHelper->GetName() << " helps and achieves "
                          << finalSuccess << std::endl;
                lockedHelper->SetSuccess(lockedHelper->GetSuccess() + finalSuccess);
            }
        }
    }

    // Record the player's completion of this assessment
    std::shared_ptr<CAssessment> sharedThis = shared_from_this();
    player->AddAssessment(sharedThis);

    mCompletedBy.push_back(player);

    // make sure there are no duplicates
    // Temporary set for holding unique shared_ptrs to ensure no duplicates
    std::set<std::shared_ptr<CPlayer>> uniqueCompletedBy;

    // Fill the set with elements from mCompletedBy to remove duplicates
    for (const auto& weakPtr : mCompletedBy)
    {
        if (auto sharedPtr = weakPtr.lock())
        {  // Ensure the weak_ptr is valid
            uniqueCompletedBy.insert(sharedPtr);
        }
    }

    // Clear mCompletedBy and repopulate it from the set, now containing only unique elements
    mCompletedBy.clear();
    for (const auto& uniqueSharedPtr : uniqueCompletedBy)
    {
        mCompletedBy.push_back(uniqueSharedPtr);
    }
}
