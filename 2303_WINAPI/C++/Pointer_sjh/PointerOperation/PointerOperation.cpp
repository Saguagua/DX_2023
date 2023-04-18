// PointerOperation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

using namespace std;

// 포인터 연산
// ptr += 2; // 2 * 4

int main()
{
	int aInt = 5;
	int* ptr = &aInt;

	cout << ptr << endl;

	ptr += 2;

	cout << ptr << endl;

	return 0;
}
