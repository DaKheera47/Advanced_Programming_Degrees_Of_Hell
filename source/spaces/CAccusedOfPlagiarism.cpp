#include "../../headers/spaces/CAccusedOfPlagiarism.h"

#include "../../headers/CGame.h"

void CAccusedOfPlagiarism::playerLanded(std::shared_ptr<CPlayer>& player,
                                        std::unique_ptr<CBoard>& board)
{
    // player moves to the Plagiarism Hearing space
    for (auto& space : board->getSpaces())
    {
        if (space->getType() == ESpaceType::PLAGIARISM_HEARING)
        {
            player->setCurrentSpace(space);
        }
    }

    // output message: '<Player> lands on Accused of Plagiarism and goes to the hearing'
    std::cout << player->getName() << " lands on Accused of Plagiarism and goes to the hearing"
              << std::endl;

    // player loses 50 motivation
    player->setMotivation(player->getMotivation() - 50);
}
