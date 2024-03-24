#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../CPlayer.h"
#include "../CSpace.h"
#include "../SChance.h"

class CBogus : public CSpace
{
private:
    std::vector<std::shared_ptr<SChance>> mChanceValues;

public:
    CBogus(ESpaceType type);

    /**
     * Handles the event when a player lands on the bogus space.
     * @param player The player who landed on the space.
     * @param board The game board.
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
