#include "../../headers/spaces/CPlagiarismHearing.h"

#include <iostream>
#include <memory>

void CPlagiarismHearing::PlayerLanded(std::shared_ptr<CPlayer>& player,
                                      std::unique_ptr<CBoard>& board)
{
    std::cout << player->GetName() << " lands on Plagiarism Hearing and supports their friend"
              << std::endl;
}
