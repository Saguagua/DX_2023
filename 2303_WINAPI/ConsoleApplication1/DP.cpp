#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> cache = vector<int>(100, -1);

int Fibonacci(int n, int& count)
{
	// 기저사항
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		count++;

	// 메모이제이션
	// 최적부분구조를 찾았을 때, cache에다가 저장해놓는 것
	if (cache[n] != -1)
		return cache[n];
	
	// 구하기
	cache[n] = Fibonacci(n - 1, count) + Fibonacci(n - 2, count);

	return cache[n];
}

int main()
{
	__int64	start = GetTickCount64();

	int count = 0;

	cout << Fibonacci(40, count) << endl;
	cout << count << endl;
	__int64 end = GetTickCount64();

	cout << end - start << " ms" << endl;
	return 0;
}