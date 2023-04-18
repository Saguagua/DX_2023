// Class_Operator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Vector2
{
public :
    Vector2()
    : x(0), y(0)
    {

    }

    Vector2(int x, int y) 
    : x(x), y(y) 
    {
        this->x = x;
        this->y = y;
    }

    Vector2 operator+(const Vector2& other)
    {
        Vector2 result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;

        return result;
    }

    Vector2 operator*(const int& value)
    {
        Vector2 result;

        return result = Vector2(this->x * value, this->y * value);
    }

    Vector2& operator=(const Vector2& other)
    {
        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    float Length()
    {
        float result = sqrtl(x * x + y * y);
    }

    float Dot(const Vector2& other)
    {
        int x = this->x * other.x;
        int y = this->y * other.y;

        return x + y;
    }

    float Cross(const Vector2& other)
    {
        
    }

public :
    int x;
    int y;

    void Print()
    {

    }
};

//전역함수로 연산자 오버로딩
// a + b : a에 b
/*
Vector2 operator+(const Vector2& a, const Vector2& b)
{
    Vector2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
}
*/

int main()
{
    Vector2 v1 = Vector2(1, 1);
    Vector2 v2 = Vector2(2, 2);
    Vector2 v3 = v1 + v2;

    return 0;
}