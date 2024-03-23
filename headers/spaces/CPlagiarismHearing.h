#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CPlagiarismHearing : public CSpace
{
protected:
public:
    CPlagiarismHearing(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player) override;
};
