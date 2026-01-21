#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

void DeletePointer(void** ptr)
{
    if (*ptr != nullptr)
    {
        delete *ptr;
        *ptr = nullptr;
    }
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(159);
    // 
    //TODO: 메모리 릭
    int* intPointer = new int; //ms compiler기준으로 int는 4바이트가 맞습니다.
    delete intPointer;

    int a = 1;
    //포인터 변수 선언 및 초기화
    //void* pointer = nullptr;
    void* pointer = new int;


    DeletePointer(&pointer);
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
    //_CrtDumpMemoryLeaks();
    //std::cin.get();
}