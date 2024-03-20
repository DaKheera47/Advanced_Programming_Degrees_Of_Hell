#include "CGame.h"

#include <iostream>
#include <memory>

using namespace std;

CGame::CGame(vector<shared_ptr<CPlayer>>& players, unique_ptr<CBoard>& board)
{
    // Optionally clear current players and spaces
    mPlayers = players;
    mBoard = std::move(board);

    // set intial positions for all players
    for (const auto& player : players)
    {
        player->setCurrentSpace(mBoard->getSpaces()[0]);
    }
    // Initialize or reset the game
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

    // Print details of each space
    for (const auto& space : mBoard->getSpaces())
    {
        cout << "Space name: " << space->getName() << endl;
    }
}

// CGame::CGame(CPlayerVector& players, UniqSpaceVector& spaces, unique_ptr<CBoard>& board) {}
