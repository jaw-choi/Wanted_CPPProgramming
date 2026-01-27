#include <iostream>

//매크로 안에서 어떤 항목 앞에 #을 붙이면 무조건으로 문자열로 변환함
#define NAME(x) #x

#define PURE = 0;

//Refactoring에 사용 많이 함
//인터페이스
//순수 가상 함수만 가져야 함
//외부의 다른객체와 소통하기 위한 기법 ->외부에서 접근이 가능해야 의미가 있음 : 항상 public으로 해야 됨
class NameInterface //구현을 강제하고 싶을때
{
public:
    virtual const char* GetName() const PURE;
};

class Entity : public NameInterface
{
public:
    //const char* GetName() const { return "Entity"; }
    //const char* GetName() const { return NAME(Entity); }
    virtual const char* GetName() const { return NAME(Entity); }

private:
    int a = 0;
};

class Player : public Entity
{
public:
    Player(const char* name)
    {
	// 내부의 name 설정.
	// 크기.
	size_t length = strlen(name) + 1;

	// 할당.
	this->name = new char[length];

	// 문자열 복사.
	strcpy_s(this->name, length, name);
    }

    ~Player()
    {
	if (name)
	{
	    delete[] name;
	    name = nullptr;
	}
    }

    const char* GetName() const  { return name; }
    void Print() const { std::cout << "hi"; }

private:
    char* name = nullptr;
};

int main()
{
    Entity* entity = new Entity();
    std::cout << entity->GetName() << "\n";

    //Player* player = new Player("Jae");
    //Player* player = new Player("Jae");
    Entity* player = new Player("Jae");
    //Player* player = (Player*)new Entity();
    std::cout << player->GetName() << "\n";
    //player->Print();
    //player->Print(); player는 (Entity*)이기 때문에 부모클래스 범위로 제한

    delete player;
    delete entity;

    std::cin.get();
}