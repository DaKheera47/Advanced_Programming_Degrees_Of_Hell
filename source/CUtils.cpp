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
vector<string> CUtils::ReadFileLines(const string& filePath)
{
    ifstream file(filePath);
    vector<string> lines;
    string line;

    if (!file.is_open())
    {
        throw runtime_error("Could not open file: " + filePath);
    }

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

// Split a string by a delimiter, inspired by python's split method
vector<string> CUtils::Split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

string CUtils::Strip(string& str)
{
    // We'll start by finding the first character that is not a whitespace
    size_t first = str.find_first_not_of(" \t\n\v\f\r");
    if (first == string::npos)
    {
        // If there's no such character, the string is all whitespace
        return "";
    }

    // Then, find the last character that is not a whitespace
    size_t last = str.find_last_not_of(" \t\n\v\f\r");

    // Now, create a substring that excludes the leading and trailing whitespace
    string stripped = str.substr(first, (last - first) + 1);

    return stripped;
}

void CUtils::Replace(string& str, const string& from, const string& to)
{
    if (from.empty())
        return;

    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != string::npos)
    {
        str.replace(startPos, from.length(), to);
        startPos += to.length();  // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int CUtils::RandInt(int end)
{
    // Just call the RandInt with 2 params
    return CUtils::RandInt(1, end);
}

int CUtils::RandInt(int start, int end)
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

int CUtils::RandInt()
{
    return static_cast<int>(
        (static_cast<double>(rand()) / static_cast<double>(RAND_MAX + 1.0f)) * 10.0f + 1);
}

int CUtils::StrToInt(const string& str)
{
    try
    {
        return stoi(str);
    }
    catch (const invalid_argument& e)
    {
        throw runtime_error("Conversion error: invalid argument");
    }
    catch (const out_of_range& e)
    {
        throw runtime_error("Conversion error: out of range");
    }
}

int CUtils::CharToInt(const char& c)
{
    return c - '0';
}

template <typename T>
bool CUtils::PresentInVector(const vector<T>& vec, const T& item)
{
    return find(vec.begin(), vec.end(), item) != vec.end();
}

// Explicit instantiation of the template
// https://stackoverflow.com/questions/2351148/explicit-template-instantiation-when-is-it-used
template bool CUtils::PresentInVector<shared_ptr<CPlayer>>(const vector<shared_ptr<CPlayer>>&,
                                                           const shared_ptr<CPlayer>&);

int CUtils::GetSpaceIndex(const vector<shared_ptr<CSpace>>& spaces,
                          shared_ptr<CSpace>& pCurrentSpace)
{
    auto it =
        find_if(spaces.begin(), spaces.end(), [pCurrentSpace](const shared_ptr<CSpace>& pSpacePtr)
                { return pSpacePtr == pCurrentSpace; });

    if (it != spaces.end())
    {
        return distance(spaces.begin(), it);
    }

    return -1;  // Indicates not found
}