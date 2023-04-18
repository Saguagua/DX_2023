#include <iostream>

using namespace std;

// Function : 함수

// 과제 1:
// 가위바위바위보, 스무고개 완성하고
// 함수화 시키기

// 과제 2:
// 별찍기
// 1. 플레이어한테 숫자를 입력받음
// 2. 5라고 입력 받았을 시
// *
// **
// ***
// ****
// *****

// extra
// 1. 구조체
// 2. 구조체와 함수
// 3. 포인터와 함수

// F(x) = y
// x : 매개변수
// y : 반환 값

// 함수 시그니쳐
// int Add(int a, int b)
// 반환형식 함수이름(매개변수)
int Add(int a, int b)
{
	// main[result][][]  Add[][][int a, int b]
	return a + b;
}

// 함수 오버로딩
// -> 함수 이름이 같을 경우, 매개변수의 형식이나 개수에 따라 함수가 여러개 만들어질 수 있다.
int Add(int a, int b, int c)
{

	return a + Add(b,c);
}

int Add(int a, int b, int c, int d)
{
	return a + Add(b, c, d);
}

int Add(float a, float b)
{
	return a + b;
}

int Add(int a, int b, int c, int d, int e , int f = 1) // 기본인자
{
	return Add(a, b, c, d) + e + f;
}

// void : 공허한... 
void PrintNum(int num)
{
	cout << num << endl;
}
// min 부터 max까지의 랜덤한 값 뽑기
int RandomNum(int min, int max)
{
	int result = 0;

	result = rand() % (max - min + 1) + min;

	return result;
}
void PrintHello(void)
{
	cout << "Hello World!" << endl;
}

// 재귀함수 : 함수가 자기 자신을 호출하는 함수
// Factorial : 5! ... 5x4x3x2x1
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}

// StackOverFlow 스택오버플로우
// 컴파일 과정에서 재귀함수로 인해 스택영역이 초과했을 때 발생

int main()
{
	// Stack 영역
	// - 지역변수
	// - 매개변수

	// main[][][]
	// [지역변수][반환주소값][매개변수]

	int result = 0;
	// main[result][][]
	// [지역변수][반환주소값][매개변수]
	result = Add(1, 2, 3, 4, 5);
	result = Factorial(10000);

	cout << result << endl;

	return 0;
}