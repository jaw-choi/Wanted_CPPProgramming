#include <iostream>
#include <Windows.h>

#define MYTEXT(value) L##value 
#define MYTEST(value1,value2) value1##value2
//##은 파라미터 두개를 무식하게 붙임

//클래스 내부에서 문자열을 나누기
class Player
{
    //public,protected,private 
    //접근 한정자/접근 제한자
    //접근 가능한 범위를 설정.
public://접근제한자
    //생성자 (Constructor)
    //객체를 생성할때 호출되는 특별한 함수
    //반환형이 없고, 클래스 이름과 동일
    Player(const char* inName) {
        //문자열 복사
        //name = inName;

        //1.저장 공간 확보
        // ->확보할 공간의 크기를 알아야 함.
        size_t length = strlen(inName) + 1;//+1:널문자
        name = new char[length]; //동적할당 
        //2. 문자열 복사.
        //memcpy(name, inName, length);
        strcpy_s(name, length, inName);
    }
    ~Player() {
        //동적할당 해제
        if (name)// == name != nullptr
        {
            delete[] name;
            name = nullptr;

        }
    }
private://접근제한자
    char* name = nullptr;//허용된지 얼마안됨(생성과 동시에 초기화하는것)


};

int main(void)
{
    //문자열
    const char*  testString = "Jae";
    std::cout << testString << "\n";
    //본래는 수정이 안되는 문자열

    //문자 배열도 가능
    char buffer[4] = { 'J', 'a', 'e','\0'};
    std::cout << buffer << "\n";

    Player player("Jae");

    //const wchar_t* wideString = L"Hello wide string"; //wide character type => L 붙임
    const wchar_t* wideString = MYTEXT("Hello wide string"); //매크로 활용
    
    std::wcout << wideString << TEXT("\n");

    auto test = MYTEST(10, 20);

    std::wcout << test << TEXT("\n");
    std::cin.get();
     
}