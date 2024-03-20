#pragma once

#include <vector>

#include "CSpace.h"

class CBoard
{
private:
    CSpace* spaces;

public:
    // Constructors
    CBoard(std::string filename);
    ~CBoard();
};
