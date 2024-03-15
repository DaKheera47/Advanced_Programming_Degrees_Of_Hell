#include "CBoard.h"

#include <iostream>

#include "CUtils.h"
using namespace std;

CBoard::CBoard(std::string filename)
{
    std::vector<std::string> lines = CUtils::readFileLines(filename);
    for (auto line : lines)
    {
        cout << line << endl;
    }
}

CBoard::~CBoard() {}
