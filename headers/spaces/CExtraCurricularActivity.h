#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "./CAssessment.h"
#include "./Constants.h"

class CExtraCurricularActivity : public CAssessment
{
public:
    CExtraCurricularActivity(ESpaceType type) : CAssessment(type)
    {
        mSuccess = Constants::kExtraCurricularSuccess;
        mMotivationCost = Constants::kExtraCurricularMotivationCost;
    };

    /**
     * Handles the event when a player lands on the extra-curricular activity space.
     * @param player The player who landed on the space.
     * @param board The game board.
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
