#include <iostream>

void PrintArray(int* array, int length)
{

    for (int i = 0; i < length; ++i)
    {
        std::cout << "array[" << i << "] : " << array[i] << "\n";
    }
}

int main()
{
    int array[10] = {};
    memset(array, 0, sizeof(int) * 10);
    
    // 0부터 시작. 마지막은 크기 -1.
    array[0] = 1;
    array[3] = 10;
    array[9] = 100;

    //Out of Index(range)
    //array[10] = 500; //undefined behavior
    //array[-1] = 1000; //undefined behavior
    int* arrayPointer = array;
    arrayPointer[1] = 20;
    *(arrayPointer + 2) = 30;

    //for (const int* const value : array)
    //for (const int& const value : array)  ->차이?
    //range-based loop 권장
    for (const int& value : array)
    {
        std::cout << "value : " << value << "\n";
    }

    //후위연산(i++) -> 메모리 사용o
    //전위 연산(++i) -> 메모리 사용x
    //요즘은 컴파일러가 다 최적화 해줘서 똑같음
    //for (int ix = 0; ix < 10; ++ix)
    //{
    //    std::cout << "array[" << ix << "] : " << array[ix] << "\n";
    //}
    PrintArray(array, 10);

    int* dynamicArray = new int[10];
    memset(dynamicArray, 1, sizeof(int) * 10);
    
    //배열에 값 추가
    for (int i = 0; i < 10; ++i)
    {
        dynamicArray[i] = (i + 1);
    }
    delete[] dynamicArray;

    std::cin.get();
}