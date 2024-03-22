#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CBogus : public CSpace
{
protected:
public:
    CBogus(ESpaceType type) : CSpace(type){};
};
