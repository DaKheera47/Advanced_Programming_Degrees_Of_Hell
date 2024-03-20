#include "CBoard.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "CUtils.h"
using namespace std;

CBoard::CBoard(string filename)
{
    ifstream file(filename);
    vector<string> lines;
    string line;

    if (!file.is_open())
    {
        throw runtime_error("Could not open file: " + filename);
    }

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    for (size_t idx = 0; idx < lines.size(); ++idx)
    {
        string line = lines[idx];
        string spaceName;

        char spaceType = line[0];

        // remove the first 2 characters from line
        if (line.length() >= 2)
        {
            line.erase(0, 2);
        }

        for (auto ch : line)
        {
            if (ch != EOF && !isdigit(ch))
            {
                spaceName += ch;
            }
        }

        // strip line
        line = CUtils::strip(line);
        // strip spaceName
        spaceName = CUtils::strip(spaceName);

        CUtils::replace(line, spaceName, "");

        // strip line
        line = CUtils::strip(line);

        string spaceMotivation = "Unknown";
        string spaceSuccess = "Unknown";
        string spaceYear = "Unknown";

        // if at this point line isn't empty, it means this space has a motivation, success and year
        vector<string> spaceDetails = CUtils::split(line, ' ');
        try
        {
            spaceMotivation = spaceDetails.at(0);
            spaceSuccess = spaceDetails.at(1);
            spaceYear = spaceDetails.at(2);
        }
        catch (const std::out_of_range& e)
        {
            // std::cerr << "Error: Attempted to access an out-of-range element in
            // 'spaceDetails'.\n";
        }

        // cout << "LINE: " << line << endl;

        cout << "space type: " << spaceType << ", space name: " << spaceName
             << ", Motivation: " << spaceMotivation << ", Success: " << spaceSuccess
             << ", Year: " << spaceYear << endl;
    }
}

CBoard::~CBoard() {}
