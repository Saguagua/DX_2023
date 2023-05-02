#include <iostream>
#include <queue>

using namespace std;

// priority_queue
//- 힙 트리
// -- 완전이진트리
// -- 힙이론을 더한 것
// --
//

class Priority_Queue
{
public:
	void push(const int& value)
	{
		// 완전 이진트리 규칙 : 맨 마지막 부분에 추가
		v.push_back(value);
		
		// 힙 규칙
		int now = v.size() - 1;

		while (true)
		{
			if (now <= 0)
				break;
			int parent = (now - 1) / 2;

			if (v[parent] > v[now])
				break;
			std::swap(v[now], v[parent]);
			now = parent;
		}

	}

	void pop()
	{
		//완전 이진트리 규칙
		v[0] = v.back();
		v.pop_back();

		while (true)
		{

		}
	}
private:
	vector<int> v;
};

int main()
{
	priority_queue<int> pq;

	pq.push(15);
	pq.push(10);
	pq.push(15);
	pq.push(11);
	pq.push(300);
	pq.push(152);
	pq.push(156);
	pq.push(1);

	while (true)
	{
		if (pq.empty())
			break;
		cout << pq.top() << endl;
		pq.pop();
	}
}