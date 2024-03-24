#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CWelcomeWeek : public CSpace
{
public:
    CWelcomeWeek(ESpaceType type) : CSpace(type){};

    /**
     * Handles the event when a player lands on the welcome week space.
     * @param player The player who landed on the space.
     * @param board The game board.
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
