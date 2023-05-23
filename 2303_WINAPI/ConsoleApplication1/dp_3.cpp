#include <iostream>
#include <vector>

using namespace std;

// {1 2 8 5 3 7 10}

//부분 수열 : 인접에 상관없이 순서에 맞는 부분 수열
//{1 2 8}
// {1 8 7}
//부분 증가 수열 : 부분 수열이며 수열이 증가하는 형태
//{1 5 7}
//최장 부분 증가 수열 : 부분 증가 수열 중 길이가 제일 긴 것
//{1 2 5 7 10}
// {1 2 3 7 10}

//1 : 5
//2 : 4
//3 : 1
//4 : 2
//5 : 1
//6 : 0

vector<int> v1 = {1, 2, 8, 3, 7, 10};
vector<int> v2 = {5, 6, 7, 8, 1, 2, 3};

//1 : 6
//2 : 2
//3 : 1
//4 : 0
//5 : 2
//6 : 1
//7 : 0

//쪼개서 해당 인덱스까지의 최장 부분 증가 수열을 구하면 된다.
//최장은 어떻게 구할까

//각 숫자마다 자신보다 더 큰 숫자가 몇 개인지 카운트

//for문으로 넘어갈 숫자가 많고, 자신보다 큰 숫자 찾기(넘어갈 숫자가 같다면 그 중 작은 걸로)
vector<int> cache = vector<int>(v1.size(), -1);
vector<int> countAll = vector<int>(v1.size(), -1);
int target = v1.size();

int LIS(int index)
{
	if (v1[index] < v1[index + 1])
		return 1;
	
	if (cache[index] != -1)
		return cache[index];
	
	cache[index] = LIS(index - 1) + 1;
		
}


int main()
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = i + 1; j < v1.size(); j++)
		{
			if (v1[i] < v1[j])
				countAll[i]++;
		}
	}
	
	int answer = LIS(v1.size());
	cout << answer << endl;

	return 0;
}