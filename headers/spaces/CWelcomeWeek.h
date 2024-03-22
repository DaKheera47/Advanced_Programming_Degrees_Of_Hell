#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CWelcomeWeek : public CSpace
{
protected:
public:
    CWelcomeWeek(ESpaceType type) : CSpace(type){};
};
