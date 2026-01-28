#include <iostream>

int main(void)
{
    FILE* file = nullptr;

    //&file은 실제 파일이아니라 파일을다룰 수 있는 포인터다. 즉 파일에 접근하기 위한'키'의 역할
    fopen_s(&file, "Test.txt","rb");//rt:read text, rb:read binary

    //파일 읽기 실패
    if (!file)
    {
        std::cout << "Failed to read file.\n";
        __debugbreak();
    }
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);

    std::cout << "FileSize: " << fileSize << "\n";

    // !(중요) 파일 크기 가늠한뒤에 다시 처음부터 읽으려면 FP 되돌려야 함.
    //fseek(file, 0, SEEK_SET);//아래와 같음
    rewind(file);

    //블록단위로 읽기
    //읽은 데이터를 저장하기 위한 공간.
    
    char* buffer = new char(fileSize);
    size_t readSize = fread(buffer, sizeof(char), fileSize, file);
    
    std::cout << "readSize: " << readSize << "\n";
    std::cout << buffer;
    delete buffer;
    ////파일 읽기
    //char data[256] = {};
    //while (true)
    //{
    //    if (!fgets(data, 256, file))
    //        break;
    //    std::cout << data;
    //}

    //파일 쓰기
    //const char* message = "프로그램에서 작성한 문자열 값입니다.";
    //fputs(message, file);

    fclose(file);
    return 0;
}