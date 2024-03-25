#include "CSpinner.h"

#include <string>
#include <vector>

#include "CUtils.h"
#include "Constants.h"

using namespace std;

int CSpinner::spinIdx = 0;

const std::string Constants::kRandFilePath = "./static/rand_seed_666.txt";

int CSpinner::Spin()
{
    if (Constants::kRandomMode == 0)
    {
        return CUtils::RandInt(10);
    }

    vector<string> randInts = CUtils::ReadFileLines(Constants::kRandFilePath);

    int result = CUtils::StrToInt(randInts[spinIdx]);

    spinIdx++;

    // Reset the index if we reach the end of the file
    if (spinIdx >= randInts.size())
    {
        spinIdx = 0;
    }

    return result;
}
