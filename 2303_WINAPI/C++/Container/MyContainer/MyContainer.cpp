#include <iostream>
#include <vector>
#include <list>
#include "VectorClass.h"
#include "ListClass.h"

using namespace std;

int main()
{
#pragma region 백터
	vector<int> v;
	vector<int>().swap(v); //임시 객체로 바꿔친다. 임시 객체는 이 줄이 끝나면 소멸자 호출하기 때문에 사라진다
#pragma endregion


	vector<int> v2;

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	list<int> l2;

	l2.push_back(1);
	l2.push_back(3);
	l2.push_back(5);
	l2.push_back(7);
	l2.push_back(9);

	vector<int>::iterator viter;

	for (viter = v2.begin(); viter != v2.end(); viter++)
		cout << *viter << endl;

	list<int>::iterator liter;

	for (liter = l2.begin(); liter != l2.end(); liter++)
		cout << *liter << endl;

	for (liter = l2.begin(); liter != l2.end(); liter++)

	return 0;
}
