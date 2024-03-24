#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CGame.h"
#include "../CSpace.h"

class CPlayer;

class CAssessment : public CSpace, public std::enable_shared_from_this<CAssessment>
{
protected:
    // needs to know who has completed the assessment
    std::vector<std::weak_ptr<CPlayer>> mCompletedBy;

public:
    CAssessment(ESpaceType type) : CSpace(type){};

    ~CAssessment() override;

    /**
     * Handles the event when a player lands on the assessment space.
     * @param player The player who landed on the space.
     * @param board The game board.
     * @see https://embeddedartistry.com/blog/2017/01/11/stdshared_ptr-and-shared_from_this/
     */
    void PlayerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
