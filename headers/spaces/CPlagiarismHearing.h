#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CPlagiarismHearing : public CSpace
{
protected:
public:
    CPlagiarismHearing(ESpaceType type) : CSpace(type){};
};
