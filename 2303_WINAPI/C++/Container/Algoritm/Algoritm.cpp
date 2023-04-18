#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(15);
	v.push_back(30);
	v.push_back(17);
	v.push_back(5);
	v.push_back(150);

#pragma region 자리 찾기
	//v에서 3이 있는지 자리 찾기 (index형)
	int index = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 3)
		{
			index = i;
			break;
		}
			
	}

	vector<int>::iterator iterator = v.begin();

	for (iterator; iterator != v.end(); iterator++)
	{
		if (*iterator == 3)
			break;
	}
	cout << *iterator << endl;
	iterator = find(v.begin(), v.end(), 3);
	if (iterator != v.end())
		cout << *iterator << endl;
	else
		cout << "없음" << endl;
#pragma endregion
#pragma region 보다 큰 원소 찾기
	// v에서 5보다 큰 첫번 째 원소 찾기

	iterator = v.begin();

	for (iterator; iterator != v.end(); iterator++)
	{
		if (*iterator > 5)
			break;
	}

	if (iterator == v.end())
		cout << "5보다 큰 값이 없습니다." << endl;

	cout << *iterator << endl;

	struct Finder_find_if
	{
		bool operator()(const int& value)
		{
			return (value > findNum);
		}

		int findNum;
	};

	Finder_find_if finder1;
	finder1.findNum = 5;
	iterator = find_if(v.begin(), v.end(), finder1);

	//v에서 5보다 큰 원소 개수 세기
	//모든 원소가 다 5보다 큰가요
	//하나라도 50보다 큰 원소가 있나요
	//모든 원소에 5를 곱하는 작업을 해주세요
	//중복되는 원소가 있다면 중복을 제거해주세요
	//값이 25인 원소를 지워주세요
	//20보다 큰 데이터를 갖는 원소들을 지워주세요
#pragma endregion


	return 0;
}
