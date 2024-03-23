#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CAccusedOfPlagiarism : public CSpace
{
protected:
public:
    CAccusedOfPlagiarism(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
