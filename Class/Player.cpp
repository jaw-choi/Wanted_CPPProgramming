#include "Player.h"
#include <iostream>

//기본값 설정/ 자원 할당.
Player::Player()
{
}

Player::Player(const char* inName) //: x(0), y(0), speed(0)
{
    size_t length = strlen(inName) + 1;
    name = new char[length];
    //복사처리
    strcpy_s(name, length, inName);
}

//자원 해제.
Player::~Player()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

void Player::Move(int deltaX, int deltaY)
{
    int newX = GetX() + deltaX;
    int newY = GetY() + deltaY;
    SetX(newX);
    SetY(newY);
}