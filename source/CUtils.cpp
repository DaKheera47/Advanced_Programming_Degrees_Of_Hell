#include "CUtils.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Read a file's lines into a vector of strings
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

// Split a string by a delimiter, inspired by python's split method
std::vector<std::string> CUtils::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

string CUtils::strip(std::string& str)
{
    // We'll start by finding the first character that is not a whitespace
    size_t first = str.find_first_not_of(" \t\n\v\f\r");
    if (first == std::string::npos)
    {
        // If there's no such character, the string is all whitespace
        return "";
    }

    // Then, find the last character that is not a whitespace
    size_t last = str.find_last_not_of(" \t\n\v\f\r");

    // Now, create a substring that excludes the leading and trailing whitespace
    std::string stripped = str.substr(first, (last - first) + 1);

    return stripped;
}

void CUtils::replace(std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return;

    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();  // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
