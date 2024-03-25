#include "../../headers/spaces/CExtraCurricularActivity.h"

#include "../../headers/CDebugUtils.h"
#include "../../headers/CUtils.h"

void CExtraCurricularActivity::PlayerLanded(std::shared_ptr<CPlayer>& player,
                                            std::unique_ptr<CBoard>& board)
{
    // Check if player has already completed the assessment
    for (const auto& weakPlayer : mCompletedBy)
    {
        auto sharedPlayer = weakPlayer.lock();
        if (sharedPlayer && sharedPlayer == player)
        {
            // message output
            std::cout << player->GetName() << " has already completed " << mName << std::endl;
            // Player has already completed this assessment, no further action is taken.
            return;
        }
    }
    // Calculate the final success and motivational cost, accounting for shared efforts if
    // applicable
    int finalSuccess = mSuccess;
    int finalMotivationCost = mMotivationCost;

    if (mCompletedBy.size() >= 1)
    {
        finalSuccess /= (mCompletedBy.size() + 1);
        finalMotivationCost /= (mCompletedBy.size() + 1);
    }

    // Verify if the player has enough motivation to do this extra curricular activity
    if (player->GetMotivation() < finalMotivationCost)
    {
        std::cout << player->GetName() << " doesn't have the " << finalMotivationCost
                  << " motivation to complete " << mName << std::endl;

        // Insufficient motivation, player cannot attempt the assessment.
        return;
    }

    player->SetMotivation(player->GetMotivation() - finalMotivationCost);
    player->SetSuccess(player->GetSuccess() + finalSuccess);

    std::cout << player->GetName() << " undertakes " << mName << " extra curricular activity for "
              << finalMotivationCost << " and achieves " << finalSuccess << std::endl;

    if (mCompletedBy.size() >= 1)
    {
        for (auto& helper : mCompletedBy)
        {
            auto lockedHelper = helper.lock();
            if (lockedHelper && lockedHelper != player)
            {
                // output message
                std::cout << "\t" << lockedHelper->GetName() << " motivates " << player->GetName()
                          << " by " << finalMotivationCost << " by joining their activity"
                          << std::endl;
                std::cout << "\t" << lockedHelper->GetName() << " also achieves " << finalSuccess
                          << std::endl;

                // increase the motivation of the helper
                lockedHelper->SetMotivation(lockedHelper->GetMotivation() + finalMotivationCost);
                lockedHelper->SetSuccess(lockedHelper->GetSuccess() + finalSuccess);
            }
        }
    }

    mCompletedBy.push_back(player);
}
