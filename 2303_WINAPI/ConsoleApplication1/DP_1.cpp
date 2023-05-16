#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache = vector<vector<int>>(101, vector<int>(101, -1));

int Combine(int n, int m)
{
	if (n < 0 || m < 0)
		return 0;
	if (n == m)
		return 1;
	if (n == 1)
		return 1;

	if (cache[n][m] != -1)
		return cache[n][m];

	cache[n][m] = Combine(n-1, m-1) + Combine(n-1, m);
	return cache[n][m];
}

int main()
{
	cout << Combine(5, 3) << endl;

	vector<int> v = {1,2,3,4,5,6,7,8,9};

	while (true)
	{
		if (std::next_permutation(v.begin(), v.end()))
		{
			for (auto value : v)
			{
				cout << value << ", ";
			}
		}
	}

	return 0;
}