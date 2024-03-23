#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CBonus : public CSpace
{
protected:
public:
    CBonus(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player) override;
};
