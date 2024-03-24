#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../CPlayer.h"
#include "../CSpace.h"
#include "../SChance.h"

class CBonus : public CSpace
{
public:
    CBonus(ESpaceType type);

    /**
     * Handles the event when a player lands on the bonus space.
     * @param player The player who landed on the space.
     * @param board The game board.
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
