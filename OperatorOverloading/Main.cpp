#include <iostream>

class Point
{
public:
    Point(int x = 0, int y = 0) : x(x), y(y)
    { }

    //덧셈
    Point Add(const Point& other) //멤버함수 = 해당 클래스의 객체와 연관있는 함수(this*사용됨)
    {
        return Point(x + other.x, y + other.y);
    }
    //friend Point Add(const Point& left, const Point& right); // 비멤버함수 = 해당 클래스의 객체와 연관이 없는 함수
    friend Point Add(const Point& left, const Point& right);


    //Point operator+(const Point& other)//멤버함수
    //{
    //    return Point(x + other.x, y + other.y);
    //}
    
    friend Point operator+(const Point& left, const Point& right)
    {

        return Point(left.x + right.x, left.y + right.y);
    }
public:
    int x = 0;
    int y = 0;
private:
    int z = 0;
};
//연산자 오버로딩하면 가장 첫번째항은 자기자신이다!

Point Add(const Point& left, const Point& right) //비멤버함수 left가 this가 되는것임
{
    
    return Point(left.x + right.x, left.y + right.y);
}
std::ostream& operator<<(std::ostream& os, const Point& point) 
{
    return os << "(" << point.x << "," << point.y << ")" << "\n";
     
}
int main(void)
{
    Point p1(1, 1);
    Point p2(5, 5);
    Point p3(p1.x + p2.x, p1.y + p2.y);
    Point p4 = p1.Add(p2);
    Point p5 = Add(p1, p2);
    Point p6 = p1 + p2; // p1.operator+(p2);
    std::cout << "(" << p3.x << "," << p3.y << ")" << "\n";
    std::cout << p3 << "\n";
    std::cout.operator<<(10).operator<<(20);
    operator<<(std::cout,p3);

    std::cin.get();
}