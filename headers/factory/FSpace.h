#pragma once
#include "../CSpace.h"
#include "../enums/ESpaceType.h"

class FSpace
{
public:
    FSpace(){};
    std::shared_ptr<CSpace> CreateNewSpace(ESpaceType incomingSpace);
};
