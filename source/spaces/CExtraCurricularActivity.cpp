#include "../../headers/spaces/CExtraCurricularActivity.h"

#include "../../headers/CDebugUtils.h"
#include "../../headers/CUtils.h"

void CExtraCurricularActivity::PlayerLanded(std::shared_ptr<CPlayer>& player,
                                            std::unique_ptr<CBoard>& board)
{
    DEBUG_PRINT("Player " + player->GetName() + " has completed the " + mName
                + " extra curricular activity.");

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
        DEBUG_PRINT("Player " + player->GetName() + " has already completed the " + mName
                    + " extra curricular activity.");
        return;
    }

    if (player->GetMotivation() < mMotivationCost)
    {
        DEBUG_PRINT("Player " + player->GetName()
                    + " does not have enough motivation to complete the " + mName
                    + " extra curricular activity.");
        return;
    }

    int finalSuccess = mSuccess;
    int finalMotivationCost = mMotivationCost;

    if (mCompletedBy.size() > 1)
    {
        finalSuccess /= mCompletedBy.size();
        finalMotivationCost /= mCompletedBy.size();
    }

    player->SetSuccess(player->GetSuccess() + finalSuccess);
    player->SetMotivation(player->GetMotivation() - finalMotivationCost);

    std::cout << player->GetName() << " undertakes " << mName << " for " << finalMotivationCost
              << " and achieves " << finalSuccess << std::endl;

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

    mCompletedBy.push_back(player);
}
