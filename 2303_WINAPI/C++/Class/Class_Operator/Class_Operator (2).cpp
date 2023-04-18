#include <iostream>

using namespace std;

// 과제
// 1. Player 클래스 만들고 Monster 클래스 만들고
// 2. Player 1명과 몬스터 배열로 10마리 생성하기
// 3. Player가 죽거나, 몬스터 배열 10마리가 다 죽으면 게임 종료

class Vector2
{
public:
	Vector2()
	: x(0) , y(0)
	{
	}

	Vector2(int x, int y)
	: x(x), y(y)
	{
		//  * this
		// this->x = x;
	}

	// 복사대입 생성자
	Vector2(const Vector2& other)
	: x(other.x), y(other.y)
	{
		cout << "복사대입생성자" << endl;
	}

	void PrintVector2()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
	}

	// 벡터의 덧셈 연산자 오버로딩
	Vector2 operator+(const Vector2& other)
	{
		Vector2 result;
		result.x = (*this).x + other.x;
		result.y = this->y + other.y;

		return result;
	}
	
	// 과제 -

	Vector2 operator*(const int& value)
	{
		Vector2 result;
		return result = Vector2(this->x * value, this->y * value);
	}

	// 복사대입연산자 - 암시적으로 생성되는 연산자
	// a = b : a에다 b를 대입하고, a의 원본을 반환한다.
	Vector2& operator=(const Vector2& other)
	{
		cout << "복사대입연산자 호출" << endl;
		x = other.x;
		y = other.y;

		return *this;
	}

	// 길이
	// 스칼라 : 힘 또는 길이 /  벡터 : 길이, 방향
	float Length() const // 뒤에 있는 const는 함수 내부에서 멤버변수를 건드리지 마라.
	{
		float result = sqrtf(x * x + y * y);

		return result;
	}

	float Dot(const Vector2& other) const
	{
		float result = x * other.x + y * other.y;
		return result;
	}

	float Cross(const Vector2& other) const
	{
		float result = x * other.y - other.x * y;

		return result;
	}

	float Angle() const
	{
		// cos으론 라디안 음수,양수 판단이 불가능하다.
		/*float projection = this->Dot(Vector2(1, 0));
		float lengthA = 1;
		float lengthB = this->Length();

		float cos = projection / (lengthA * lengthB);

		return acos(cos);*/

		float result = atan2f(y, x);
		return result;
	}

public:
	int x;
	int y;
};

// 전역함수로 연산자 오버로딩하기
// a + b : a에 b값을 더하고 더한 값을 리턴한다.
//Vector2 operator+(const Vector2& a, const Vector2& b)
//{
//	Vector2 result;
//	result.x = a.x + b.x;
//	result.y = a.y + b.y;
//
//	return result;
//}


int main()
{
	Vector2 v1 = Vector2(1, 1);
	Vector2 v2 = Vector2(2, 2);
	Vector2 v3 = v1 + (v2);
	v3.PrintVector2();

	Vector2 v4 = v2; // 복사대입 생성자 호출
	v3 = v2;		// 복사대입 연산자 호출

	v4 = Vector2(3, 4);

	cout << v4.Length() << endl;
	cout << v4.Angle() << endl;

	return 0;
}