#include "../../headers/spaces/CBonus.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../headers/CSpinner.h"
#include "../../headers/CUtils.h"

using namespace std;

CBonus::CBonus(ESpaceType type) : CSpace(type)
{
    // Populate the mChanceValues vector with the values from "BonusData.csv"
    vector<string> bonusContent = CUtils::ReadFileLines("./static/BonusData.csv");

    for (const string& line : bonusContent)
    {
        vector<string> row = CUtils::Split(line, ',');

        int spinResult = CUtils::StrToInt(row[0]);
        string message = row[1];
        int value = CUtils::StrToInt(row[2]);

        shared_ptr<SChance> chance = make_shared<SChance>(spinResult, message, value);
        mChanceValues.push_back(chance);
    }
}

void CBonus::PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board)
{
    const int spinResult = CSpinner::Spin();

    for (const auto& chance : mChanceValues)
    {
        if (spinResult == chance->spinResult)
        {
            cout << player->GetName() << " spins " << spinResult << endl;

            player->SetMotivation(player->GetMotivation() + chance->value);
            cout << chance->message << ". " << "Gain Motivation of " << chance->value << endl;
        }
    }
}
