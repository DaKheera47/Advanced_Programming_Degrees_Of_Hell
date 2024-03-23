#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CGame.h"
#include "../CPlayer.h"
#include "../CSpace.h"

class CAssessment : public CSpace
{
protected:
    // needs to know who has completed the assessment
    std::vector<std::weak_ptr<CPlayer>> mCompletedBy;

public:
    CAssessment(ESpaceType type) : CSpace(type){};
    ~CAssessment() override
    {
        // clear the vector of players who have completed the assessment, so they can be destroyed
        mCompletedBy.clear();
    };
    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
