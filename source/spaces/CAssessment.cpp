#include "../../headers/spaces/CAssessment.h"

#include <iostream>
#include <memory>

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
    bool alreadyCompleted = false;
    for (const auto& weakPlayer : mCompletedBy)
    {
        auto sharedPlayer = weakPlayer.lock();
        if (sharedPlayer && sharedPlayer == player)
        {
            alreadyCompleted = true;
            break;
        }
    }

    if (alreadyCompleted)
    {
        // Player has already completed this assessment, no further action is taken.
        return;
    }

    // Verify if the player has enough motivation to attempt this assessment
    if (player->GetMotivation() < mMotivationCost)
    {
        // Insufficient motivation, player cannot attempt the assessment.
        return;
    }

    // Calculate the final success and motivational cost, accounting for shared efforts if
    // applicable
    int finalSuccess = mSuccess;
    int finalMotivationCost = mMotivationCost;

    if (mCompletedBy.size() > 1)
    {
        finalSuccess /= mCompletedBy.size();
        finalMotivationCost /= mCompletedBy.size();
    }

    // Apply the assessment's effects to the player
    player->SetSuccess(player->GetSuccess() + finalSuccess);
    player->SetMotivation(player->GetMotivation() - finalMotivationCost);

    std::cout << player->GetName() << " completes " << mName << " for " << finalMotivationCost
              << " and achieves " << finalSuccess << std::endl;

    // Acknowledge contributions from other players, if any
    if (mCompletedBy.size() > 1)
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
}
