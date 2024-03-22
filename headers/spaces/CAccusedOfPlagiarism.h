#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CAccusedOfPlagiarism : public CSpace
{
protected:
public:
    CAccusedOfPlagiarism(ESpaceType type) : CSpace(type){};
};
