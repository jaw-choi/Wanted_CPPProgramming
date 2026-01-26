#include <iostream>

//매크로 안에서 어떤 항목 앞에 #을 붙이면 무조건으로 문자열로 변환함
#define NAME(x) #x

#define PURE = 0;

class NameInterface
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
    std::cout << sizeof(Entity)<<"\n";
    std::cout << sizeof(Player);
    delete player;
    delete entity;

    std::cin.get();
}