#include "CUtils.h"

#include <fstream>
#include <iostream>

using namespace std;

std::vector<std::string> CUtils::readFileLines(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::vector<std::string> lines;
    std::string line;
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}