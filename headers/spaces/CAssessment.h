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
    CPlayerVector mCompletedBy;

public:
    CAssessment(ESpaceType type) : CSpace(type){};
    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
