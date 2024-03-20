#pragma once

#include <memory>
#include <vector>

#include "CPlayer.h"
#include "CSpace.h"
#include "CSpinner.h"

using CPlayerVector = std::vector<std::unique_ptr<CPlayer>>;

class CGame
{
private:
    CSpinner spinner;
    CPlayerVector players;
    std::vector<CSpace*> spaces;

public:
    // Getters
    CPlayerVector getPlayers();
    std::vector<CSpace*> getSpaces();

    // Adding players
    void addPlayer(std::unique_ptr<CPlayer> player);
    void addPlayer(const CPlayerVector& players);

    // Adding spaces
    void addSpace(CSpace* space);
    void addSpace(const std::vector<CSpace*>& spaces);

    // Start game
    void start();

    // constructor
    CGame();
    CGame(const CPlayerVector& players, const std::vector<CSpace*>& spaces);
};
