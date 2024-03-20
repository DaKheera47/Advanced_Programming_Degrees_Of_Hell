#pragma once

#include <vector>

#include "CSpace.h"

class CBoard
{
private:
    std::vector<std::shared_ptr<CSpace>> mSpaces;

public:
    // Constructors
    CBoard(std::string filename);
    ~CBoard();

    // getters
    std::vector<std::shared_ptr<CSpace>> getSpaces();
};
