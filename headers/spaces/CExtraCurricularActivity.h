#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CExtraCurricularActivity : public CSpace
{
protected:
public:
    CExtraCurricularActivity(ESpaceType type) : CSpace(type){};
};
