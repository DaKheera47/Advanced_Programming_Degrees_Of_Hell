#include <iostream>
#include <memory>
using namespace std;
#include "CPlayer.h"
// #include "CGame.h"

int main()
{
    // unique_ptr<CGame> currentGame = make_unique<CGame>();
    unique_ptr<CPlayer> player1 = make_unique<CPlayer>("Player 1", 100, 100, 1);
    unique_ptr<CPlayer> player2 = make_unique<CPlayer>("Player 2", 100, 100, 1);

    // Add players and spaces to the game
    cout << "Adding players and spaces to the game" << endl;
    cout << "Player 1: " << *player1 << endl;
    cout << "Player 2: " << *player2 << endl;
    // currentGame->addSpace(new CAssessment());

    // Start the currentGame
    // currentGame->start();

    return 0;
}
