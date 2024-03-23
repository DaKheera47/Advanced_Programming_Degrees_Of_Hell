#include "../../headers/spaces/CPlagiarismHearing.h"

void CPlagiarismHearing::playerLanded(std::shared_ptr<CPlayer>& player,
                                      std::unique_ptr<CBoard>& board)
{
    // output message
    std::cout << player->getName() << " lands on Plagiarism Hearing and supports their friend"
              << std::endl;
}
