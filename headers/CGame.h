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
    std::unique_ptr<CBoard> mBoard;

public:
    // constructor
    CGame(CPlayerVector& players, std::unique_ptr<CBoard>& board);

    // Start game
    void start();

    // play game
    void play(const int rounds);
};
