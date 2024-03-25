#pragma once

#include <string>

class Constants
{
public:
    /**
     * @brief The total number of rounds in the game
     */
    static const int kTotalRounds = 500;

    /**
     * @brief The motivation increase when a player attends Welcome Week
     */
    static const int kWwMotivInc = 250;

    /**
     * @brief The number of assessments required per year to progress
     */
    static const int kAssessmentsPerYear = 3;

    /**
     * @brief The maximum number of years in the game
     */
    static const int kMaxYears = 3;

    /**
     * @brief
     * control which method of random number generation is used
     * 0 means random mode
     * 1 means read from file, for predictable testing
     */
    static const int kRandomMode = 1;

    /**
     * @brief
     * control which file the random numbers are read from
     * give the full file path from ./
     */
    static const std::string kRandFilePath;

    /**
     * @brief
     * how much the motivation decreases when a player is accused of plagiarism
     */
    static const int kPlagiarismMotivDec = 50;
};
