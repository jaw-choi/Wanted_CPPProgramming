#include <iostream>
#include "Entity.h"
#include "../Vector.h"

namespace Wanted {


    Entity::Entity(int x, int y)
    {
        position = new Vector();
        position->x = x; // == //(*position).x = x;    
        position->y = y;
    }

    Entity::Entity(const Entity& other)
    {
        std::cout << "copy constructor called\n";
        //기본 복사 생성자가 하는일
        //주소값 복사
        //나중에 댕글링 포인터 문제 발생
        //Dangling pointer - 주인을 잃어버림.
        //-> 이미 삭제된 메모리 주소에 접근
        // 
        //얕은 복사
        position = other.position;

        //깊은 복사
        position = new Vector();

        position->x = other.position->x;
        position->y = other.position->y;
    }

    Entity::~Entity()
    {
        if (position) {
            delete position;
            position = nullptr;
        }
    }
}
