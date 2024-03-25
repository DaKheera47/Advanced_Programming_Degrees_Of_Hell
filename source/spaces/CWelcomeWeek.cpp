#include "../../headers/spaces/CWelcomeWeek.h"

#include "../../headers/CDebugUtils.h"

void CWelcomeWeek::PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    // print the player's name and the space they landed on with somethign that says it's from the
    // assessment space
    DEBUG_PRINT(player->GetName() << " landed on " << GetName() << " (CWelcomeWeek)" << std::endl);
}
