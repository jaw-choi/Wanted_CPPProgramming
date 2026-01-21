#include <iostream>

//call by value
//값 복사
//원본 값에는 영향 없음
//void Increment(int value)
//{
//    value++;
//}

//call by reference
//주소 복사
//원본 값에 영향 있음
void Increment(int& ref)
{
    ++ref;
}

//call by pointer
//주소 복사
//원본 값에 영향 있음
void Increment(int* ptr)
{
    ++(*ptr);
}

int main()
{
    //int a = 5;
    //int& ref = a;    // L-Value Reference.
    //ref = 10;
    int number = 10;
    Increment(number);
    std::cin.get();
}