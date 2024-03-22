#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CSkipClasses : public CSpace
{
protected:
public:
    CSkipClasses(ESpaceType type) : CSpace(type){};
};
