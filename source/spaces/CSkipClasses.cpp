#include "../../headers/spaces/CSkipClasses.h"

void CSkipClasses::PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    // message: <Player> lands on Skip Classes and hangs out with their dodgy mate
    std::cout << player->GetName() << " lands on Skip Classes and hangs out with their dodgy mates"
              << std::endl;
}
