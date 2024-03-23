#include "../../headers/spaces/CBogus.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../headers/CSpinner.h"
#include "../../headers/CUtils.h"

using namespace std;

CBogus::CBogus(ESpaceType type) : CSpace(type)
{
    // populate the chanceValues vector with the values from "BogusData.csv"
    // get the file content
    vector<string> bogusContent = CUtils::readFileLines("./static/BogusData.csv");

    // iterate through the file, and print
    for (const string& line : bogusContent)
    {
        vector<string> row = CUtils::split(line, ',');

        int spinResult = CUtils::strToInt(row[0]);
        string message = row[1];
        int value = CUtils::strToInt(row[2]);

        // create the SChance objects
        shared_ptr<SChance> chance = make_shared<SChance>(spinResult, message, value);

        // add the SChance objects to the chanceValues vector
        chanceValues.push_back(chance);
    }
}

void CBogus::playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    // spin the spinner again
    const int spinResult = CSpinner::spin();

    // take action according to the thingy given in the table
    for (const auto& chance : chanceValues)
    {
        if (spinResult == chance->spinResult)
        {
            player->setMotivation(player->getMotivation() + chance->value);
            cout << player->getName() << " lands on Bogus" << endl;
            cout << chance->message << ". " << "Loses Motivation of " << chance->value << endl;

            cout << player->getName() << " has " << player->getMotivation() << " motivation"
                 << endl;
        }
    }
}
