#include <iostream>
#include <memory>

class Player
{
public:
    Player()
    {
        std::cout << "생성자 호출\n";
    }
    ~Player()
    {
        std::cout << "소멸자 호출\n";
    }

    //unique_ptr가 복사 막는방법 
    // 요즘방법
    Player(const Player& other) = delete;
    Player& operator=(const Player& other)  = delete;
    //예전 방법
private:
    //Player(const Player& other) {}
    //Player& operator=(const Player& other) { return *this; }

};

//void Function(std::unique_ptr<Player>& player)
//{
//    std::cout << "Player 받음\n";
//}

//void Function(std::unique_ptr<Player>& player)
//{
//    //참조해버리면 아래처럼 delete 가능하기 때문에 안좋은코드
//    //위험한 코드.
//    Player* rawPointer = player.get();
//    delete rawPointer;
//    std::cout << "Player 받음\n";
//}

//void Function(Player* player)
//{
//    //참조해버리면 아래처럼 delete 가능하기 때문에 안좋은코드
//    //위험한 코드.
//    std::cout << "Player 받음\n";
//}

void Function(Player& player)
{
    //참조해버리면 아래처럼 delete 가능하기 때문에 안좋은코드
    //위험한 코드.
    //delete rawPointer;//->delete 안됨
    std::cout << "Player 받음\n";
}

void Function1(std::unique_ptr<Player> player)
{
    std::cout << "Player 받음\n";
}

int main(void)
{
    //Player player;
    //Player player2 = player; //복사생성자 호출
    //player2 = player;        //대입연산자 호출



    // unique_ptr 객체 선언.
    //Player player0 = new Player();
    std::unique_ptr<Player> player1 = std::make_unique<Player>();
    //std::unique_ptr<Player> player2 = std::move(player1);

    //Function(player1);
    Function(*player1);//역참조하면 참조로 넘길 수 있음
    Function1(std::make_unique<Player>());

    
    //std::unique_ptr<Player> player2 = player1; //불가


    return 0;
}

