#include <iostream>

using namespace std;

//[index] : 색인
//배열을 인덱스로 접근하면 소요시간이 1이다.

//배열 선언
//int arr[10] = {0};

//특
//1. 메모리상 순서대로 나열
//2. 인덱스로 접근하는 시간 상수
//3. 배열의 이름은 포인터 처럼 동작
//4. int arr[10] : 정적배열

//정적 배열 특 (정적 : 프로그램 시작하면 정해지는 것)
//1. 프로그램 시작 시 크기 주어진다.
//2. 크기 수정 불가

struct Player {
	int hp;
	int atk;
	string name;
};

void PrintArr(int arr[], int size);

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

	int* ptr = arr; //arr == &arr[0]
	//ptr = &arr[4];
	//cout << *ptr << endl;

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	cout << endl << endl;

//for (int i = 0; i < 10; i++) {
//	cout << *ptr << endl;
//	ptr++;
//}

	//배열 크기 알아내기
	cout << sizeof(arr) << endl; 
	int arrSize = sizeof(arr) / sizeof(int);

	PrintArr(arr, arrSize);

	Player playerArr[10];
	int size = sizeof(playerArr) / sizeof(Player);

	for (int i = 0; i < size; i++) {
		playerArr[i].hp = i * 10;
		playerArr[i].atk = i;
		playerArr[i].name = "a";
	}

	return 0;
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {

	}
}
