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
    CSpinner spinner;
    CPlayerVector mPlayers;
    std::unique_ptr<CBoard> mBoard;

public:
    // constructor
    CGame(CPlayerVector& players, std::unique_ptr<CBoard>& board);

    // // Getters
    // CPlayerVector getPlayers();
    // std::vector<CSpace*> getSpaces();

    // // Adding mPlayers
    // void addPlayer(std::unique_ptr<CPlayer> player);
    // void addPlayer(const CPlayerVector& mPlayers);

    // // Adding mSpaces
    // void addSpace(CSpace* space);
    // void addSpace(const std::vector<CSpace*>& mSpaces);

    // Start game
    void start();

    // play game
    void play(const int& rounds = 10);
};
