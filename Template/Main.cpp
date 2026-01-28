#include <iostream>

//template<class T> template 처음 나왔을때 class라는 keyword씀 (옛날표현)
template<typename T>
inline void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//void Swap(int& a, int & b)
//{
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//
//void Swap(float& a, float& b)
//{
//    float tmp = a;
//    a = b;
//    b = tmp;
//}

int main(void)
{
    int a = 10;
    int b = 20;
    std::cout << a << " ," << b << "\n";
    Swap(a, b); //=> Swap<int>(a, b)
    std::cout << a << " ," << b << "\n";

    float fa = 10.5;
    float fb = 20.1;
    std::cout << fa << " ," << fb << "\n";
    Swap(fa, fb); //=> Swap<float>(fa, fb);
    std::cout << fa << " ," << fb << "\n";
    return 0;
}
