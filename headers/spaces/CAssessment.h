#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CAssessment : public CSpace
{
protected:
public:
    CAssessment(ESpaceType type) : CSpace(type){};
};
