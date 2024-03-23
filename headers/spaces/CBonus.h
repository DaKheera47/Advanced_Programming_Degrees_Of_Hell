#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../CPlayer.h"
#include "../CSpace.h"
#include "../SChance.h"

class CBonus : public CSpace
{
private:
    std::vector<std::shared_ptr<SChance>> chanceValues;

public:
    CBonus(ESpaceType type);
    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
