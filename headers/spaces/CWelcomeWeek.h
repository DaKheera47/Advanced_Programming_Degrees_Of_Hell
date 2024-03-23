#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CWelcomeWeek : public CSpace
{
protected:
public:
    CWelcomeWeek(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player) override;
};
