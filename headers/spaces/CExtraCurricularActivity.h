#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "../CSpace.h"

class CExtraCurricularActivity : public CSpace
{
protected:
public:
    CExtraCurricularActivity(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player) override;
};
