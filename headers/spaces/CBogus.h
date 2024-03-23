#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CBogus : public CSpace
{
protected:
public:
    CBogus(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
