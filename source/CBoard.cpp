#include "CBoard.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../headers/factory/FSpace.h"
#include "CDebugUtils.h"
#include "CUtils.h"
using namespace std;

CBoard::CBoard(string filename)
{
    unique_ptr<FSpace> spaceFactory = make_unique<FSpace>();

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

        std::shared_ptr<CSpace> space =
            spaceFactory->CreateNewSpace(ESpaceType(CUtils::charToInt(spaceType)));

        space->setName(spaceName);

        try
        {
            spaceMotivation = spaceDetails.at(0);
            spaceSuccess = spaceDetails.at(1);
            spaceYear = spaceDetails.at(2);

            space->setMotivationalCost(CUtils::strToInt(spaceMotivation));
            space->setSuccess(CUtils::strToInt(spaceSuccess));
            space->setYear(CUtils::strToInt(spaceYear));
        }
        catch (const std::out_of_range& e)
        {
            // if it's a space without the extra details
            // a space may or may not have extra details
            // cout << "Out of Range Error on " << e.what() << endl;
        }

        mSpaces.push_back(space);
    }

    // for (const auto& space : mSpaces)
    // {
    //     cout << "space type: " << static_cast<int>(space->getType())
    //          << ", space name: " << space->getName()
    //          << ", Motivation: " << space->getMotivationalCost()
    //          << ", Success: " << space->getSuccess() << ", Year: " << space->getYear() << endl;
    // }
}

CBoard::~CBoard() {}

std::vector<std::shared_ptr<CSpace>> CBoard::getSpaces()
{
    return mSpaces;
}

std::vector<std::shared_ptr<CSpace>> CBoard::getSpaces(ESpaceType type)
{
    vector<std::shared_ptr<CSpace>> spaces;

    for (const auto& space : mSpaces)
    {
        if (space->getType() == type)
        {
            spaces.push_back(space);
        }
    }

    return spaces;
}
