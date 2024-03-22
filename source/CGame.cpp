#include "CGame.h"

#include <iostream>
#include <memory>

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
    // Print number of players and spaces
    cout << "Number of players: " << mPlayers.size() << endl;

    // Print details of each player
    for (const auto& player : mPlayers)
    {
        cout << "Player name: " << player->getName() << " is currently at "
             << player->getCurrentSpace()->getName() << endl;
    }

    // // Print details of each space
    // for (const auto& space : mBoard->getSpaces())
    // {
    //     cout << "Space name: " << space->getName() << endl;
    // }
}

// CGame::CGame(CPlayerVector& players, UniqSpaceVector& spaces, unique_ptr<CBoard>& board) {}
