#include "CGame.h"

#include <iostream>
#include <memory>

#include "CUtils.h"
#include "Constants.h"

using namespace std;

CGame::CGame(CPlayerVector& players, unique_ptr<CBoard>& board)
{
    mPlayers = players;
    mBoard = std::move(board);

    // set intial positions for all players to the 0th element on the board, so the first space
    for (const auto& player : players)
    {
        player->setCurrentSpace(mBoard->getSpaces()[0]);
    }
}

// Start game
void CGame::start()
{
    // intro message
    cout << "Welcome to Scumbag College" << endl;
}

void CGame::play(const int rounds)
{
    for (int roundNum = 1; roundNum <= rounds; roundNum++)
    {
        cout << endl << "ROUND " << roundNum << endl;
        cout << "=========" << endl;

        for (auto& player : mPlayers)
        {
            // spin the spinner
            int spinResult = CSpinner::spin();

            cout << player->getName() << " spins " << spinResult << endl;

            // move the player
            shared_ptr<CSpace> currentSpace = player->getCurrentSpace();
            int currentPosIndex = CUtils::getSpaceIndex(mBoard->getSpaces(), currentSpace);
            int boardSize = mBoard->getSpaces().size();
            int newPosIndex = (currentPosIndex + spinResult) % boardSize;

            // Move the player to the new position
            player->setCurrentSpace(mBoard->getSpaces()[newPosIndex]);

            // Check for rollover
            bool hasPassedWelcomeWeek = newPosIndex <= currentPosIndex;

            // doing additional things if the player has passed the Welcome Week
            if (hasPassedWelcomeWeek)
            {
                // motivation goes up by Constants::WW_MOTIV_INC
                player->setMotivation(player->getMotivation() + Constants::WW_MOTIV_INC);
                // message: ‘<Player> attends Welcome Week and starts year <year> more motivated!'
                cout << player->getName() << " attends Welcome Week and starts year "
                     << player->getYearOfStudy() << " more motivated!" << endl;

                // year only increases if a player has done 3 of the assessments of this year.
                vector<shared_ptr<CAssessment>> thisYearAssignments =
                    player->getCompletedAssessments(player->getYearOfStudy());

                // make sure there are at least 3 assessments completed of the same year
                if (thisYearAssignments.size() < Constants::ASSESSMENTS_PER_YEAR)
                {
                    cout << player->getName()
                         << " has not completed enough assessments to progress to the next year."
                         << endl;
                    continue;
                }

                // year increases by 1
                player->setYearOfStudy(player->getYearOfStudy() + 1);

                // check if the player has crossed year 3
                if (player->getYearOfStudy() > Constants::MAX_YEARS)
                {
                    cout << "Congratulations! " << player->getName() << " has graduated!" << endl;

                    cout << "Final stats: ";
                    cout << *player;

                    // end the game
                    return;
                }
            }

            // get the player's current space to calculate the effect
            player->getCurrentSpace()->playerLanded(player, mBoard);

            cout << *player;
        }
    }
}
