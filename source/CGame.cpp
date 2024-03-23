#include "CGame.h"

#include <iostream>
#include <memory>

#include "CUtils.h"

using namespace std;

CGame::CGame(CPlayerVector& players, unique_ptr<CBoard>& board)
{
    mPlayers = players;
    mBoard = std::move(board);

    // set intial positions for all players to the 0th element on the board, so the first space
    for (const auto& player : players)
    {
        player->setCurrentSpace(mBoard->getSpaces()[0]);
    }
}

// Start game
void CGame::start()
{
    // intro message
    cout << "Welcome to Scumbag College" << endl;
}

void CGame::play(const int& rounds)
{
    for (int roundNum = 1; roundNum <= rounds; roundNum++)
    {
        cout << endl << "ROUND " << roundNum << endl;
        cout << "=========" << endl;

        for (auto& player : mPlayers)
        {
            // spin the spinner
            int spinResult = spinner.spin();

            cout << player->getName() << " spins " << spinResult << endl;

            // move the player
            shared_ptr<CSpace> currentSpace = player->getCurrentSpace();
            int currentPosIndex = CUtils::getSpaceIndex(mBoard->getSpaces(), currentSpace);
            int boardSize = mBoard->getSpaces().size();
            int newPosIndex = (currentPosIndex + spinResult) % boardSize;

            // Move the player to the new position
            player->setCurrentSpace(mBoard->getSpaces()[newPosIndex]);

            // get the player's current space to calculate the effect
            player->getCurrentSpace()->playerLanded(player, mBoard);

            // print out the player's new success and motivation:
            std::cout << player->getName() << "'s motivation is " << player->getMotivation()
                      << " and success is " << player->getSuccess() << std::endl
                      << std::endl;
        }
    }
}
