#include <iostream>
#include <cstdio>
#include "Player.h"

Player::Player() : Player(0, 0, 0.f) {}

Player::Player(int id, int score, float attack) : id(id), score(score), attack(attack)
{

}
Player::~Player()
{
    //stack에 있으니 따로 x
}

//직렬화 (파일에)
void Player::Serialize(const char* path)
{
    //Open
    FILE* file = nullptr;
    errno_t error = fopen_s(&file, path, "wt");

    //Exception
    if (!file)
    {
        std::cout << "Failed to open file.\n";
        __debugbreak();
        return;
    }

    char outputData[256] = {};

    // 파일에 저장할 데이터 만들기.
    //sprintf_s(outputData, 256, "id = %d, score = %d, attack = %f", id, score, attack);
    fprintf_s(file, "id = %d, score = %d, attack = %f", id, score, attack);

    //파일에 데이터 기록
    //size_t writtenSize = fwrite(outputData, sizeof(char), 256, file);


    //close
    fclose(file);

}
//역직렬화 (파일에서)
void Player::Deserialize(const char* path)
{
    //Open
    FILE* file = nullptr;
    errno_t error = fopen_s(&file, path, "rt");

    //Exception
    if (!file)
    {
        std::cout << "Failed to open file.\n";
        __debugbreak();
        return;
    }


    // 파일에서 읽어오기.
    fscanf_s(file, "id = %d, score = %d, attack = %f", &id, &score, &attack);

    //close
    fclose(file);
}