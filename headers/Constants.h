#pragma once

#include <string>

// Forward declarations
class CPlayer;
class CAssessment;

using CPlayerVector = std::vector<std::shared_ptr<CPlayer>>;
using CAssessmentVector = std::vector<std::shared_ptr<CAssessment>>;
using CPlayerWeakPtrVector = std::vector<std::weak_ptr<CPlayer>>;

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

    /**
     * @brief
     * starting motivation level of a player
     */
    static const int kStartingMotivation = 1000;

    /**
     * @brief
     * starting success level of a player
     */
    static const int kStartingSuccess = 0;

    /**
     * @brief
     * starting year of a player
     */
    static const int kStartingYear = 1;

    /**
     * @brief
     * extra-curricular activity success level
     */
    static const int kExtraCurricularSuccess = 20;

    /**
     * @brief
     * extra-curricular activity motivation cost
     */
    static const int kExtraCurricularMotivationCost = 100;
};
