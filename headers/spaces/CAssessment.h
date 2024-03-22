#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CSpace.h"

class CAssessment : public CSpace
{
protected:
public:
    // Explicitly calling a base class constructor
    CAssessment(ESpaceType type) : CSpace(type){};
};

using UniqAssessmentVector = std::vector<std::unique_ptr<CAssessment>>;
using UniqAssessment = std::unique_ptr<CAssessment>;
