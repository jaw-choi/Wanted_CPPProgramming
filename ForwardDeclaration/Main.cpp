#include <iostream>
//#include "Entity/Entity.h"
#include "Entity.h"
//#include <Entity/Entity.h>
//#include <Entity.h>
// <>범위가 작음 ""범위가 큼, <>하고싶으면 프로젝트 속성에서 경로 추가해줘야함
//시스템적성격 외부라이브러리 => <>
// 나 or 우리팀 => ""

void TestFunction(Wanted::Entity entity)
{
    std::cout << "TestFunction called\n";
}

int main()
{
    Wanted::Entity entity(10, 20);
    Wanted::Entity entity2(entity);
    Wanted::Entity entity3 = entity2;

    std::cin.get();
    return 0;
}