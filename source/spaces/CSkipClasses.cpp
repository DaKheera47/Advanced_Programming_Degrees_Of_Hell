#include "../../headers/spaces/CSkipClasses.h"

void CSkipClasses::playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    // print the player's name and the space they landed on with somethign that says it's from the
    // assessment space
    std::cout << player->getName() << " landed on " << getName() << " (CSkipClasses)" << std::endl;
}
