#include "../../headers/spaces/CBonus.h"

void CBonus::playerLanded(std::shared_ptr<CPlayer>& player)
{
    // print the player's name and the space they landed on with somethign that says it's from the
    // assessment space
    std::cout << player->getName() << " landed on " << getName() << " (CBonus)" << std::endl;
}
