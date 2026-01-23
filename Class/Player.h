#pragma once  //중복 include 방지 구문 (컴파일러 구문)

//클래스
class Player
{
    //접근 한정자/접근 제한자
    //클래스 내부의 속성을 어디까지 노출시킬지 결정
    //public/protected      /private
    //공개  /상속자에게만 공개/비공개
public:
    //Setter
    //공개 함수(메소드) ->메시지
    //parameter를 받지 않는 생성자 = 기본 생성자.

    //Player() = default;
    //~Player() = default;
    Player();
    Player(const char* inName);
    ~Player();


    inline void SetX(const int inX) {
        /*if (inX < 0) {
            x = 0;
        }
        else*/
        x = inX;
    }
    void SetY(const int inY) {
        y = inY;
    }
    void SetSpeed(const int inSpeed) {
        speed = inSpeed;
    }
    //Getter
    inline int GetX() const
    {
        return x;
    }
    inline int GetY() const
    {
        return y;
    }

    void Move(int deltaX, int deltaY);
    /*void PrintPosition() const
    {
        std::cout << "Player Position: (" << x << ", " << y << ")\n";
    }*/
private:
    int x = 0;
    int y = 0;
    int speed = 0;

    //이름값(문자열)
    char* name = nullptr;
};

//ecpm이 높아야 광고수입업