#include "../../headers/spaces/CExtraCurricularActivity.h"

#include "../../headers/CDebugUtils.h"
#include "../../headers/CUtils.h"

void CExtraCurricularActivity::playerLanded(std::shared_ptr<CPlayer>& player,
                                            std::unique_ptr<CBoard>& board)
{
    // debug print contents of mCompletedBy
    DEBUG_PRINT("Player " << player->getName() << " has completed the " << mName
                          << " extra curricular activity." << std::endl);

    // make sure player hasn't already completed the extra curricular activity
    if (CUtils::presentInVector(mCompletedBy, player))
    {
        DEBUG_PRINT("Player " << player->getName() << " has already completed the " << mName
                              << " extra curricular activity." << std::endl);

        // nothing happens
        return;
    }

    // check if the player has enough motivation
    if (player->getMotivation() < mMotivationalCost)
    {
        DEBUG_PRINT("Player " << player->getName()
                              << " does not have enough motivation to complete the " << mName
                              << " extra curricular activity." << std::endl);

        // nothing happens
        return;
    }

    int finalSuccess = mSuccess;
    int finalMotivationalCost = mMotivationalCost;

    // if completed by another player, motivational cost and success rate are divided between all
    // players
    if (mCompletedBy.size() > 1)
    {
        finalSuccess /= mCompletedBy.size();
        finalMotivationalCost /= mCompletedBy.size();
    }

    // update player's success and motivation
    player->setSuccess(player->getSuccess() + finalSuccess);
    player->setMotivation(player->getMotivation() - finalMotivationalCost);

    // if player has completed the extra curricular activity, print out a message
    std::cout << player->getName() << " undertakes " << mName << " for " << finalMotivationalCost
              << " and achieves " << finalSuccess << std::endl;

    // if player needed help to complete the extra curricular activity, print out a message
    if (mCompletedBy.size() > 1)
    {
        for (auto& helper : mCompletedBy)
        {
            if (helper != player)
            {
                std::cout << "\t..." << helper->getName() << " motivates " << player->getName()
                          << " and achieves " << finalSuccess << std::endl;

                // update helper's success
                helper->setSuccess(helper->getSuccess() + finalSuccess);
                helper->setMotivation(helper->getMotivation() - finalMotivationalCost);
            }
        }
    }

    // add the player to mCompletedBy
    mCompletedBy.push_back(player);
}
