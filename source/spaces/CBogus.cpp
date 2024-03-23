#include "../../headers/spaces/CBogus.h"

void CBogus::playerLanded(std::shared_ptr<CPlayer>& player)
{
    // print the player's name and the space they landed on with somethign that says it's from the
    // assessment space
    std::cout << player->getName() << " landed on " << getName() << " (CBogus)" << std::endl;
}
