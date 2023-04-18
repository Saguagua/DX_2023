#include <iostream>
#include <vector>
#include <list>

using namespace std;

//vector와 list의 차이

// BigO (n^2 + n) = n^2
// 2 * n => n


//1. 임의접근 연산자
//list : 사용 불가 (n) / vecotr 사용 가능 (상수)
// 
//2. push_front 
//list : 0 (상수) / vector : x (n)
//3. 중간 삽입 삭제
// list : (삽입할 곳을 찾은 경우 상수) / vector : (n)
// 4. vector는 큰 덩어리 / list는 노드 형태의 이어진 선
// 
// list vector 공통점
// - 선형 컨테이너
//

int main()
{
	list<int> l;

	for (int i = 0; i < 1000; i++)
	{
		l.push_front(i);
	}

	list<int>::iterator iter = l.begin();
	
	for (int i = 0; i < l.size(); i++)
	{
		cout << *iter << endl;
		iter++;
	}

	return 0;
}