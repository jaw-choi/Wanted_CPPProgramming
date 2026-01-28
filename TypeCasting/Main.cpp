#include <iostream>

void PrintString(char* string)
{
    std::cout << string << "\n";
}

class A {
public:
    A() = default;
    virtual ~A() = default;
public:
    virtual void Test() {}
};

class B : public A
{

};

class C
{

};

int main(void)
{
    const char* name = "jae";
    //PrintString(name);
    PrintString(const_cast<char*>(name));

    int number = 10;
    float floatNumber = static_cast<float>(number);

    A* a = new B();
    B* b = static_cast<B*>(a); // down casting, use this more that reinterpret_cast
    B* b1 = reinterpret_cast<B*>(a); // down casting, dangerous
    B* b2 = dynamic_cast<B*>(a); //적어도 하나의 virtual 함수 필요
    A* a2 = dynamic_cast<B*>(b); //upcasting은 붙여도되고 안붙여도됨
    A* a3 = b; //upcasting은 그냥도됨
    C* c = new C();
    //=>실패이유 

    auto& ainfo = typeid(*a);
    auto& binfo = typeid(*b);
    auto& cinfo = typeid(*c);
    if (ainfo == binfo)
    {
        std::cout << " it's same";
    }

    delete a;
    std::cin.get();
}
