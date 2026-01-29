#include <iostream>
#include <functional>

//typedef int (*Adder)(int, int); // typedef
using Adder = int (*)(int, int); // using
//using Adder = std::function<int(int, int)>; // std::function
//반환형이 int이고, 파라미터를 안받는 함수.
int Function(int a, int b, Adder adder)
{
    return adder(a,b);
}

int Add(int a, int b)
{
    return a + b;
}


int main(void)
{
    //함수 포인터 선언.
    std::cout << Function(10, 20, Add) << "\n";
    std::cout << Function(10, 20, [](int a, int b) { return a + b; }) << "\n";
    
    return 0;
}