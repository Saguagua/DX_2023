#include <iostream>

using namespace std;

// 포인터
// : 가르키는 얘
// 포인터 변수 : 주소값을 담는 변수
// (자료형)* (변수이름) = (초기화);

// 크기 : 4바이트(32비트 환경), 8바이트(64비트 환경)
// (자료형)* : 포인터 변수가 가리키는 곳을 찾아가보면 해당 자료형이 있을 것이다 라는 힌트

// *(포인터변수) : 포인터 변수가 가리키는 곳으로 포탈타서 원본을 갖고온다. -> 간접연산자
// &(변수) : 주소연산자... 해당 변수의 주소를 반환한다.

int main()
{
	int aInt = 5;
	float aFloat = 1.0f;
	int* aPtr = &aInt;

	cout << aPtr << endl;
	(*aPtr)++;

	cout << aPtr << endl;
	cout << aInt << endl;

	return 0;
}