#include "CBoard.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../headers/factory/FSpace.h"
#include "CDebugUtils.h"
#include "CUtils.h"

using namespace std;

CBoard::~CBoard()
{
    // clean up the spaces
    mSpaces.clear();
}

CBoard::CBoard(const std::string& filename)
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

    for (const auto& line : lines)
    {
        string currentLine = line;
        string spaceName;

        char spaceType = currentLine[0];

        // Remove the first 2 characters from line
        if (currentLine.length() >= 2)
        {
            currentLine.erase(0, 2);
        }

        for (auto ch : currentLine)
        {
            if (ch != EOF && !isdigit(ch))
            {
                spaceName += ch;
            }
        }

        spaceName = CUtils::Strip(spaceName);

        CUtils::Replace(currentLine, spaceName, "");

        currentLine = CUtils::Strip(currentLine);

        vector<string> spaceDetails = CUtils::Split(currentLine, ' ');

        auto space =
            spaceFactory->CreateNewSpace(static_cast<ESpaceType>(CUtils::CharToInt(spaceType)));
        space->SetName(spaceName);

        try
        {
            if (spaceDetails.size() >= 3)
            {
                space->SetMotivationCost(CUtils::StrToInt(spaceDetails.at(0)));
                space->SetSuccess(CUtils::StrToInt(spaceDetails.at(1)));
                space->SetYear(CUtils::StrToInt(spaceDetails.at(2)));
            }
        }
        catch (const std::out_of_range& e)
        {
            // Handle spaces without extra details or incorrect file format gracefully.
        }

        mSpaces.push_back(space);
    }
}

std::vector<std::shared_ptr<CSpace>> CBoard::GetSpaces() const
{
    return mSpaces;
}

std::vector<std::shared_ptr<CSpace>> CBoard::GetSpaces(ESpaceType type) const
{
    vector<std::shared_ptr<CSpace>> spacesFiltered;

    for (const auto& space : mSpaces)
    {
        if (space->GetType() == type)
        {
            spacesFiltered.push_back(space);
        }
    }

    return spacesFiltered;
}
