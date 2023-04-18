#include <iostream>

using namespace std;

// 동적할당
// 
// - 생성주기 : 프로그램 생성
// - 삭제주기 : 프로그램 종료
// 
// - 생성 : 프로그램 시작 시 영역 미리 정하기, 지역 시작
// - 삭제 : 함수 종료, 지역 끝남
// heap
// - 프로그래머 메모리
// - 생성 : 프로그래머가 동적할당한 코드를 읽기 시작한 시범
// - 삭제 : 프로그래머가 delete한 코드를 읽기 시작한 시점

//동적할당
// 코드 실행될 때 운영체제(커널에 가서 HEAP영역에 몇 바이트만큼 할당해달라 요청하는 것)
// malloc free

int aInt = 1;
int bInt = 2;

int main()
{
	int cInt = 3;
	int dInt = 4;
	void* ptr = malloc(1000);
	
	/*
	int* ptr2 = (int*)ptr;

	(*ptr2) = 6;
	*/
	int* newData = new int();
	delete newData;
	cout << sizeof(newData) << endl;
	free(ptr); //동적할당 해제 안함 -> 메모리 누수

	return 0;
}