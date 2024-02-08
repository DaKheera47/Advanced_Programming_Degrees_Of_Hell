#pragma once

#include <iostream>

class CPlayer
{
private:
    std::string mName;

public:
    CPlayer(std::string name);
    ~CPlayer();

    std::string getName() { return mName; }
};

CPlayer::CPlayer(std::string name)
{
    mName = name;
}

CPlayer::~CPlayer()
{
}
