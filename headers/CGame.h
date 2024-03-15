#pragma once

#include "CPlayer.h"
#include "CSpace.h"
#include "CSpinner.h"
#include <vector>
#include <memory>

class CGame
{
private:
    CSpinner spinner;
    std::vector<std::unique_ptr<CPlayer>> players;
    std::vector<CSpace *> spaces;

public:
    // Getters
    std::vector<std::unique_ptr<CPlayer>> getPlayers();
    std::vector<CSpace *> getSpaces();

    // Adding players
    void addPlayer(std::unique_ptr<CPlayer> player);
    void addPlayer(const std::vector<std::unique_ptr<CPlayer>> &players);

    // Adding spaces
    void addSpace(CSpace *space);
    void addSpace(const std::vector<CSpace *> &spaces);

    // Start game
    void start();

    // constructor
    CGame();
    CGame(const std::vector<std::unique_ptr<CPlayer>> &players, const std::vector<CSpace *> &spaces);
};
