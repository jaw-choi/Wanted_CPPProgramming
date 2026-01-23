#include <iostream>

//게임 물체(객체).
//Gameobject / Actor / Entity(개체)

class Entity
{
    public:
    Entity() {
        std::cout << "Constructor called\n";
    }
    ~Entity() = default;
    //멤버 함수 선언 끝의 const는 
    //이 함수가 객체 상태(this)를 변경하지 않겠다는 의미입니다.
    void showName() const {

        std::cout << "Entity. \n ";
    }
    const Entity& GetSelf() const {
        // this는 자기 자신을 가리키는 '포인터'.
        return *this;
    }
};

//void showName(Entity* entity) //숨겨진 매개변수가 있음 이것이 this
//{
//    //..
//}

int main(void)
{
    //Entity* entity = nullptr;
    //entity->showName(); // 객체정보가 넘어감, 함수 호출시에는 null체크 안함, c#,java는 null체크함
    ////                  // c++은 있는지 없는지 확인안함,C는 class가 없고,
    //                    // C의 방식을 활용하기 때문에 class안에 있는 함수도 사실 전역함수임
    ////showName();
    //const int count = 5;
    //Entity entities[count];

    ////Range-based for loop ( for each loop )
    //for(const Entity& entity : entities) {
    //    entity.showName();
    //}

    //const int count = 5;
    //Entity* entities[count] = { };
    ////memset(entities, 0, sizeof(Entity*) * count);

    //for (int ix = 0; ix < count; ++ix) {//만약 후위 연산하면 내부적으로 컴파일러 메모리 써서 성능면에서 페널티있는데 요즘은 차이없음
    //    entities[ix] = new Entity();
    //}

    ///*for (Entity* entity : entities) { ->문제있음
    //    delete entity;
    //    entity = nullptr;
    //}*/
    //for (Entity*& entity : entities) {
    //    delete entity;
    //    entity = nullptr;
    //}
    Entity* entity = new Entity();
    std::cout << entity << "\n";
    std::cout << &entity->GetSelf() << "\n";

    delete entity;

    std::cin.get();
    return 0;
}