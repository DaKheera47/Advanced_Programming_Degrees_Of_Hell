#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "../CPlayer.h"
#include "./CAssessment.h"

class CExtraCurricularActivity : public CAssessment
{
protected:
public:
    CExtraCurricularActivity(ESpaceType type) : CAssessment(type)
    {
        // set sucess by default to 20
        mSuccess = 20;
    };

    void playerLanded(std::shared_ptr<CPlayer>& player, std::unique_ptr<CBoard>& board) override;
};
