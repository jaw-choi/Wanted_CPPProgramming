#include <iostream>

void DeletePointer(void*& ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

int main()
{
    //동적 할당
    char* buffer = new char[10];
    //포인터 변수 선언 및 초기화
    //void* pointer = nullptr;
    void* pointer = new int;
    DeletePointer(pointer);
    //delete pointer;
    //pointer = nullptr;
    //null check
    if (pointer != nullptr)
    {
        std::cout << "Pointer is not null\n";
    }
    else
    {
        std::cout << "Pointer is null\n";
    }

    std::cin.get();
}