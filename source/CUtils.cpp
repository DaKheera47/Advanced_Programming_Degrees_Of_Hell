#include "CUtils.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "CPlayer.h"

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

int CUtils::randInt(int end)
{
    // just call the randInt with 2 params
    return CUtils::randInt(1, end);
}

int CUtils::randInt(int start, int end)
{
    // Ensure end is greater than start
    if (end < start)
    {
        // https://en.cppreference.com/w/cpp/algorithm/swap
        swap(start, end);
    }

    int range = end - start + 1;
    return rand() % range + start;
}

int CUtils::randInt()
{
    return static_cast<int>(
        (static_cast<double>(rand()) / static_cast<double>(RAND_MAX + 1.0f)) * 10.0f + 1);
}

int CUtils::strToInt(const std::string& str)
{
    try
    {
        return std::stoi(str);
    }
    catch (const std::invalid_argument& e)
    {
        throw std::runtime_error("Conversion error: invalid argument");
    }
    catch (const std::out_of_range& e)
    {
        throw std::runtime_error("Conversion error: out of range");
    }
}

int CUtils::charToInt(const char& c)
{
    return c - '0';
}

template <typename T>
bool CUtils::presentInVector(const std::vector<T>& vec, const T& item)
{
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

// Explicit instantiation of the template
// https://stackoverflow.com/questions/2351148/explicit-template-instantiation-when-is-it-used
template bool CUtils::presentInVector<std::shared_ptr<CPlayer>>(
    const std::vector<std::shared_ptr<CPlayer>>&, const std::shared_ptr<CPlayer>&);

int CUtils::getSpaceIndex(const std::vector<std::shared_ptr<CSpace>>& spaces,
                          shared_ptr<CSpace>& currentSpace)
{
    auto it = std::find_if(spaces.begin(), spaces.end(),
                           [currentSpace](const std::shared_ptr<CSpace>& spacePtr)
                           { return spacePtr == currentSpace; });

    if (it != spaces.end())
    {
        return std::distance(spaces.begin(), it);
    }

    return -1;  // Indicates not found
}
