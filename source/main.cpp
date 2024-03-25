#include <iostream>
#include <memory>
#include <string>

#include "../headers/factory/FSpace.h"
#include "CBoard.h"
#include "CDebugUtils.h"
#include "CGame.h"
#include "CPlayer.h"
#include "CSpace.h"
#include "CUtils.h"
#include "Constants.h"

using namespace std;

int main()
{
    // Seeding the random number generator
    // Get the seed from seed.txt
    string firstLine = CUtils::ReadFileLines("./static/seed.txt")[0];
    int seed = CUtils::StrToInt(firstLine);
    DEBUG_PRINT("Seed: " << seed);
    srand(seed);

    CPlayerVector players;
    players.push_back(make_shared<CPlayer>("Vyvyan"));
    players.push_back(make_shared<CPlayer>("Rick"));
    // players.push_back(make_shared<CPlayer>("Neil"));
    // players.push_back(make_shared<CPlayer>("Mike"));

    for (const auto& player : players)
    {
        DEBUG_PRINT("Player name: " << player->GetName());
    }

    // Create the board
    unique_ptr<CBoard> pBoard = make_unique<CBoard>("./static/degrees.txt");

    unique_ptr<CGame> pCurrentGame = make_unique<CGame>(players, pBoard);

    // Start the current game
    pCurrentGame->Start();

    pCurrentGame->Play(Constants::kTotalRounds);

    pCurrentGame->End();

    return 0;
}
