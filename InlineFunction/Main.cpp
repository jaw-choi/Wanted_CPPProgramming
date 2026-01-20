#include <iostream>

//inline == 용량 포기, 속도 get
//용량 or 속도
//인라인 함수 -> 속도 때문
#define Square(x) ((x) * (x))
__forceinline int SquareInline(int x) {
    return x * x;
}

int Squareint(int x) {
    return x * x;
}

int main() {
    int number = Squareint(5);

}