#pragma once

#include <memory>
#include <vector>

#include "CBoard.h"
#include "CPlayer.h"
#include "CSpace.h"
#include "CSpinner.h"

using CPlayerVector = std::vector<std::shared_ptr<CPlayer>>;
using CSpaceVector = std::vector<std::unique_ptr<CSpace>>;

class CGame
{
private:
    CPlayerVector mPlayers;
    std::unique_ptr<CBoard> mpBoard;

public:
    /**
     * @brief Constructor for CGame
     *
     * @param players The vector of players in the game
     * @param pBoard The game board
     */
    CGame(CPlayerVector& players, std::unique_ptr<CBoard>& pBoard);

    /**
     * @brief Start the game
     */
    void Start();

    /**
     * @brief Play the game for a specified number of rounds
     *
     * @param rounds The number of rounds to play
     */
    void Play(const int rounds);

    /**
     * @brief End the game
     * prints out the final scores of the players, and declares the winner
     */
    void End();
};
