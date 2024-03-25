#include "../../headers/spaces/CAccusedOfPlagiarism.h"

#include "../../headers/CGame.h"
#include "../../headers/Constants.h"

void CAccusedOfPlagiarism::PlayerLanded(std::shared_ptr<CPlayer>& player,
                                        std::unique_ptr<CBoard>& board)
{
    // player moves to the Plagiarism Hearing space
    for (auto& space : board->GetSpaces())
    {
        if (space->GetType() == ESpaceType::PLAGIARISM_HEARING)
        {
            player->SetCurrentSpace(space);
        }
    }

    // output message: '<Player> lands on Accused of Plagiarism and goes to the hearing'
    std::cout << player->GetName() << " lands on Accused of Plagiarism and goes to the hearing"
              << std::endl;

    // player loses 50 motivation
    player->SetMotivation(player->GetMotivation() - Constants::kPlagiarismMotivDec);

    // output message: '<Player> loses 50 motivation'
    std::cout << player->GetName() << " loses " << Constants::kPlagiarismMotivDec << " motivation "
              << std::endl;
}
