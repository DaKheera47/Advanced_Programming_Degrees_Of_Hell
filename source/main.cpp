#include <iostream>
#include <memory>
using namespace std;

#include "../headers/factory/FSpace.h"
#include "CBoard.h"
#include "CDebugUtils.h"
#include "CGame.h"
#include "CPlayer.h"
#include "CSpace.h"
#include "CUtils.h"
#include "Constants.h"

int main()
{
    // seeding the random number generator
    // get the seed from seed.txt
    string firstLine = CUtils::readFileLines("./static/seed.txt")[0];
    int seed = CUtils::strToInt(firstLine);
    DEBUG_PRINT("Seed: " << seed);
    srand(seed);

    CPlayerVector players;
    players.push_back(make_shared<CPlayer>("Vyvyan"));
    players.push_back(make_shared<CPlayer>("Rick"));
    // players.push_back(make_shared<CPlayer>("Neil"));
    // players.push_back(make_shared<CPlayer>("Mike"));

    for (const auto& player : players)
    {
        DEBUG_PRINT("Player name: " << player->getName());
    }

    // create the board
    unique_ptr<CBoard> board = make_unique<CBoard>("./static/degrees.txt");

    unique_ptr<CGame> currentGame = make_unique<CGame>(players, board);

    // Start the currentGame
    currentGame->start();

    currentGame->play(Constants::TOTAL_ROUNDS);

    return 0;
}
