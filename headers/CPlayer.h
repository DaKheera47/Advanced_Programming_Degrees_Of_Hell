#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "./spaces/CAssessment.h"
#include "CSpace.h"

class CAssessment;

class CPlayer
{
private:
    std::string mName;
    int mLevelOfMotivation = 1000;
    int mSuccess = 0;
    int mYearOfStudy = 1;

    std::shared_ptr<CSpace> mCurrentSpace;
    std::vector<std::shared_ptr<CAssessment>> mAssessments;

public:
    CPlayer(std::string name, int levelOfMotivation, int success, int yearOfStudy);
    CPlayer(std::string name);
    ~CPlayer();

    // cout operator overload
    friend std::ostream& operator<<(std::ostream& os, const CPlayer& player);

    // setters
    void setMotivation(int levelOfMotivation);
    void setCurrentSpace(std::shared_ptr<CSpace> space);
    void setName(const std::string& name) { mName = name; }
    void setSuccess(int success) { mSuccess = success; }
    void setYearOfStudy(int yearOfStudy) { mYearOfStudy = yearOfStudy; }
    void addAssessment(std::shared_ptr<CAssessment>& assessment)
    {
        mAssessments.push_back(assessment);
    }

    // getters
    std::shared_ptr<CSpace> getCurrentSpace();
    std::string getName() const { return mName; }
    int getMotivation() const { return mLevelOfMotivation; }
    int getSuccess() const { return mSuccess; }
    int getYearOfStudy() const { return mYearOfStudy; }
    std::vector<std::shared_ptr<CAssessment>> getCompletedAssessments() const
    {
        return mAssessments;
    }
    std::vector<std::shared_ptr<CAssessment>> getCompletedAssessments(int year);
};
