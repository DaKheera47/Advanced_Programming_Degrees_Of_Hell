#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CSkipClasses : public CSpace
{
protected:
public:
    CSkipClasses(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player) override;
};
