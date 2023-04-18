#include <iostream>
#include <vector>

using namespace std;

// 동적 배열
// 런타임 도중 크기가 바뀔 수 있다
// 

void PrintIntvector(const vector<int>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}
}



int main()
{
	vector<int> v;

	v.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		cout << "size : " << v.size() << endl;
		cout << "capacity : " << v.capacity() << endl;
	}

	return 0;

}