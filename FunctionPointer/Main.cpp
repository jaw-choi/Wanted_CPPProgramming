//#include <iostream>
//#include <functional>
//
////typedef int (*Adder)(int, int); // typedef
//using Adder = int (*)(int, int); // using
////using Adder = std::function<int(int, int)>; // std::function
////반환형이 int이고, 파라미터를 안받는 함수.
//int Function(int a, int b, Adder adder)
//{
//    return adder(a,b);
//}
//
//int Add(int a, int b)
//{
//    return a + b;
//}
//
//
//int main(void)
//{
//    //함수 포인터 선언.
//    std::cout << Function(10, 20, Add) << "\n";
//    std::cout << Function(10, 20, [](int a, int b) { return a + b; }) << "\n";
//    
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

// Functor (함수 객체)
class Less
{
public:

    //호출 연산자 오버로딩
    bool operator()(int a, int b)
    {
        return a < b;
    }
private:
};

// Functor (함수 객체)
class Greater
{
public:

    //호출 연산자 오버로딩
    bool operator()(int a, int b)
    {
        return a > b;
    }
private:
    //상태도 추가로 관리 가능
};

int main()
{
    std::vector<int> array = { 1,2,3,4,5,6,7,8,9,10 };
    //Less less;
    //Greater greater;
    //정렬
    //std::sort(array.begin(), array.end(), greater);
    //람다
    auto greater = [](int a, int b) -> bool {return a > b; };
    //auto result = greater(number1, number2);
    std::sort(array.begin(), array.end(), greater);
    /*std::sort(
        array.begin(),
        array.end(),
        [](int a, int b) -> bool {return a > b; }
    );*/
    int sum = 0;
    //auto test = []() {};
    std::for_each(
        array.begin(),
        array.end(),
        [&](int item) {sum += item; }
    );

    std::cout << "Sum = " << sum << "\n";
    for (const auto arr : array)
        std::cout << arr << " ";
    std::cout << "\n";
    return 0;
}
