#include <iostream>
#include <memory>
using namespace std;

#include "CBoard.h"
#include "CGame.h"
#include "CPlayer.h"
#include "CUtils.h"

int main()
{
    // seeding the random number generator
    // get the seed from seed.txt
    string firstLine = CUtils::readFileLines("./static/seed.txt")[0];
    int seed = CUtils::strToInt(firstLine);
    srand(seed);

    CPlayerVector players;
    players.push_back(make_unique<CPlayer>("Vyvyan"));
    players.push_back(make_unique<CPlayer>("Rick"));

    // Add players and spaces to the game
    cout << "Adding players and spaces to the game" << endl;

    for (const auto& player : players)
    {
        cout << *player << endl;
    }

    unique_ptr<CBoard> board = make_unique<CBoard>("./static/degrees.txt");

    // Start the currentGame
    // currentGame->start();

    return 0;
}
