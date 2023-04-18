#include <iostream>

using namespace std;

// 과제 1
// 구구단, 별찍기 함수처리

// 과제 2
// 스무고개 만들기
// - 컴퓨터는 난수 생성 (1 ~ 500)
// - 플레이어가 숫자를 입력,
// - 플레이어가 입력 숫자에 따라서... 플레이어 숫자가 컴퓨터 숫자보다 작으면
// ... "플레이어의 숫자가 컴퓨터 숫자보다 작습니다" 출력
// - 플레이어 숫자와 컴퓨터 숫자 같으면 맞추셨습니다. 종료
// - 20번 반복
// 
// 가위바위보 게임 만들기
// - 플레이어 입력, 컴퓨터 난수 생성
// - 0(가위), 1(바위), 2(보)
// - 20번반복... 20번 동안 가위바위보

// CPU
// - 연산장치 
// - 제어장치/논리장치
// => 계산하기

// RAM : Random Access Memory (할당되는 주소를 확실하게 알 수 없다.)
// - CPU에서 연산한 Data를 저장하는 용도 쓴다.
// - 물리적으로 HDD보다 훨씬 가깝다.
// => CPU와 가까우니 정보 저장하거나 불러오는 시간이 짧다.
// - 용량이 작다.
// - 저장한 것들이 휘발성이다.

// HDD : 
// - 물리적 멀다.
// => 저장, 불러오기 시간이 길다.
// - 용량이 매우크다.
// - 저장했던 것들이 비영구적이다.

// Function (함수)
// F(x) = y
// x : (자료형)매개변수
// y : (자료형)반환값

// void 자료형이란... 없음을 나타낸다.
// - 매개변수로 올 때는 생략 가능

// 함수 시그니쳐 (함수 모양)
// int AddInt(int a, int b)
// 반환형식 함수이름(매개변수)

// Stack 영역
// 지역변수, 매개변수
// Stack Frame

void HelloWorld(void)
{
	cout << "Hello World!" << endl;
}

// 함수오버로딩 : 시그니처 중에 매개변수만 달라져도 함수를 만들 수 있는 것.
// => 함수이름은 같고 매개변수(자료형, 개수)만 다른 형식

int Add(int a, int b, int c);
int Add(int a, int b);
// 기본 매개변수(기본 인자) : 매개변수를 설정하지 않을 경우 기본으로 주는 값
int Add(int a, int b, int c, int d, int e);

// 재귀함수
// 5! = 5 x 4 x 3 x 2 x 1
int Factorial(int number)
{
	if (number == 1)
		return 1;

	return number * Factorial(number - 1);
}

// 스택오버플로우
// 스택영역은... 컴파일 할 때 크기가 정해진다.

int main()
{
	// 난수 생성
	// - 씨드
	// - 랜덤함수
	srand(unsigned int(time(nullptr))); // 씨드
	int randomNum = rand() % 50; // 0 ~ 49 까지의 랜덤한 숫자
	cout << randomNum << endl;

	int aInt = 0;
	// main[][반환주소값][aInt]
	aInt = Add(1, 2, 3, 4, 5);
	// main[][반환주소][aInt]

	cout << aInt << endl;

	aInt = Factorial(5);

	cout << aInt << endl;

	return 0;
}

int Add(int a, int b)
{
	int result = 0;
	// main[][반환주소][aInt] AddInt[a,b][반환주소값][result]
	result = a + b;

	return result;
}

int Add(int a, int b, int c)
{
	int result = 0;

	result = Add(a, b) + c;

	return result;
}

int Add(int a, int b, int c, int d, int e = 0)
{
	int result = 0;

	result = Add(a, b, c) + d + e;

	return result;
}