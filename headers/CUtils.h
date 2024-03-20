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
    static std::vector<std::string> split(const std::string& s, char delimiter);
    // https://stackoverflow.com/a/58090517
    static std::string strip(std::string& str);
    // https://stackoverflow.com/a/3418285
    static void replace(std::string& str, const std::string& from, const std::string& to);
};
