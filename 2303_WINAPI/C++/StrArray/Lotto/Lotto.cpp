#include <iostream>

using namespace std;

//로또번호 뽑기
//1~45 랜덥 7개 숫자 중복없이
//오름차순 정렬

void Swap(int& a, int& b);

int main()
{
	int lotto[7] = { 5,1,2,3,10,15,34 };
	int aInt = 3;
	int bInt = 5;
	int& aRef = aInt;
	int& bRef = bInt;

	Swap(aRef, bRef);

	cout << aInt << endl;
	cout << bInt << endl;

	return 0;
}

void Swap(int& a, int& b)
{
	int tmp = a;

	a = b;
	b = tmp;
}
