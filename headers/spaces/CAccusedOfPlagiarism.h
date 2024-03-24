#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CAccusedOfPlagiarism : public CSpace
{
public:
    /**
     * @brief Constructs a CAccusedOfPlagiarism space with the specified type.
     * @param type The type of space, should be ESpaceType::ACCUSED_OF_PLAGIARISM for this class.
     */
    CAccusedOfPlagiarism(ESpaceType type) : CSpace(type) {}

    /**
     * @brief Handles the event when a player lands on this space.
     * @param player A shared pointer to the player who landed on the space.
     * @param board A unique pointer to the game board.
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
