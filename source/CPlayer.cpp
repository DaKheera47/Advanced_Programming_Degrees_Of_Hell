#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer(std::string name, int age)
{
    mName = name;
    mAge = age;
}

CPlayer::~CPlayer()
{
    std::cout << "Destroying player: " << mName << std::endl;
}

int CPlayer::getAge()
{
    return mAge;
}

std::string CPlayer::getName()
{
    return mName;
}