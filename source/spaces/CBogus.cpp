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
    // Populate the chanceValues vector with the values from "BogusData.csv"
    vector<string> bogusContent = CUtils::ReadFileLines("./static/BogusData.csv");

    for (const string& line : bogusContent)
    {
        vector<string> row = CUtils::Split(line, ',');

        int spinResult = CUtils::StrToInt(row[0]);
        string message = row[1];
        int value = CUtils::StrToInt(row[2]);

        shared_ptr<SChance> chance = make_shared<SChance>(spinResult, message, value);
        mChanceValues.push_back(chance);
    }
}

void CBogus::PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    const int spinResult = CSpinner::Spin();

    for (const auto& chance : mChanceValues)
    {
        if (spinResult == chance->spinResult)
        {
            player->SetMotivation(player->GetMotivation() + chance->value);
            cout << player->GetName() << " lands on Bogus" << endl;
            cout << chance->message << ". " << "Loses Motivation of " << chance->value << endl;
            cout << player->GetName() << " has " << player->GetMotivation() << " motivation"
                 << endl;
        }
    }
}
