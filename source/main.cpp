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

int main()
{
    // seeding the random number generator
    // get the seed from seed.txt
    string firstLine = CUtils::readFileLines("./static/seed.txt")[0];
    int seed = CUtils::strToInt(firstLine);
    srand(seed);

    CPlayerVector players;
    players.push_back(make_shared<CPlayer>("Vyvyan"));
    players.push_back(make_shared<CPlayer>("Rick"));

    // vector<shared_ptr<CPlayer>> players;
    // players.push_back(make_shared<CPlayer>("Vyvyan"));
    // players.push_back(make_shared<CPlayer>("Rick"));

    for (const auto& player : players)
    {
        DEBUG_PRINT("Player name: " << player->getName());
    }

    // create the board
    unique_ptr<CBoard> board = make_unique<CBoard>("./static/degrees.txt");

    unique_ptr<CGame> currentGame = make_unique<CGame>(players, board);
    // Start the currentGame
    currentGame->start();

    return 0;
}
