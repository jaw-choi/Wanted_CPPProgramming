#include <iostream>
#include "Player.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //인스턴스/객체
    Player player1;
    //player1.x = 5;
    player1.SetX(5);
    //player1.y = 2;
    player1.SetY(2);

    player1.SetSpeed(10);
    player1.Move(3, 4);

    //힙
    Player* player2 = new Player("Jae");
    player2->SetX(10);
    player2->SetY(20);
    player2->Move(-5, -10);
    //(*player2).MovePlayer(*player2, -5, -10); //(-> 화살표 연산자와 동일)
    //player1.PrintPosition();
    //player2->PrintPosition();

    delete player2;
    player2 = nullptr;
    std::cin.get();
    return 0;
}