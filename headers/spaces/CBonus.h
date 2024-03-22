#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CBonus : public CSpace
{
protected:
public:
    CBonus(ESpaceType type) : CSpace(type){};
};
