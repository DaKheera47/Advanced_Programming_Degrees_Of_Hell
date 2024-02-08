#include "../headers/CPlayer.h"
#include <iostream>

using namespace std;

int main()
{
    CPlayer *player = new CPlayer("John");

    player = new CPlayer("Jane");

    cout << "Player name: " << player->getName() << endl;

    return 0;
}
