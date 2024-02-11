#include <iostream>
#include <memory>
#include "CPlayer.h"
using namespace std;

int main()
{
    unique_ptr<CPlayer> player = make_unique<CPlayer>("John", 25);

    cout << "Player name: " << player->getName() << endl;
    cout << "Player age: " << player->getAge() << endl;

    return 0;
}
