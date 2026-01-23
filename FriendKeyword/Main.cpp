#include <iostream>

//private -> 접근 막음
//friend  -> 접근 허용 예외를 둠

//template -> 컴파일 타임에 확정 -> 컴파일 시간 늘어남
class Entity 
{
    friend class Player; // Entity를 player에게 허용해준다
    //접근 한정자/제한자  (visibility modifier)
public:
    //int GetX() const { return x; }
    friend void ShowEntity(Entity& entity);//2
    friend void Add(Entity& e1, const Entity& e2); // friend는 외부 함수를 대상

    void Add(Entity& other)
    {
        x += other.x;
        y += other.y;
    }
    //접근 한정자는 클래스한정, 객체에는 영향 없음 // other.x; <- 다른주체라 접근가능
private:
    int x = 0;
    int y = 0;
};


class Player
{

public:

    void Add(Entity& other)
    {
        x += other.x;
        y += other.y;
    }
    //Entity에서 friend class Player; 선언해줘서 접근 가능
private:
    int x = 0;
    int y = 0;
};


void Add(Entity& e1, const Entity& e2)
{
    int x, y;
    x = e1.x + e2.x;
    y = e1.y + e2.y;
    std::cout << x << ", " << y << std::endl;
}

void ShowEntity(Entity& entity) //1 
{
    entity.x = 1;
    std::cout << entity.x << ", " << entity.y << std::endl;
}

int main(void)
{
    Entity entity1;
    Entity entity2;

    entity1.Add(entity2);
    Add(entity1, entity2);

    ShowEntity(entity1);
    Add(entity1, entity2);
    return 0;
}