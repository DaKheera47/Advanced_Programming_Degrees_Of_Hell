#pragma once

#include <vector>

class CUtils
{
private:
public:
    // Constructors
    CUtils();
    ~CUtils();

    // methods
    static std::vector<std::string> readFileLines(const std::string& filePath);
};
