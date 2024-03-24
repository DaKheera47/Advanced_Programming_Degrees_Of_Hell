#include "CSpinner.h"

#include <string>
#include <vector>

#include "CUtils.h"
#include "Constants.h"

using namespace std;

int CSpinner::spinIdx = 0;

const std::string Constants::kRandFilePath = "./static/rand_seed_48.txt";

int CSpinner::Spin()
{
    if (Constants::kRandomMode == 0)
    {
        return CUtils::RandInt(10);
    }

    vector<string> randInts = CUtils::ReadFileLines(Constants::kRandFilePath);

    int result = CUtils::StrToInt(randInts[spinIdx]);

    spinIdx++;

    return result;
}
