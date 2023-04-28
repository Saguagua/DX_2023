#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent;

//인접행렬
void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][6] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][0] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;
	adjacent[5][3] = true;

	adjacent[6][1] = true;
	adjacent[6][6] = true;
}

void BFS(int here)
{
	discovered = vector<bool>(7, false);
	parent = vector<int>(7, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	parent[here] = here;

	while (true)
	{
		if (q.empty())
			break;

		int here = q.front();
		q.pop();

		for (int there = 0; there < adjacent.size(); there++)
		{
			
			if (discovered[there] == true)
				continue;
		}
	}
}

int main()
{
	CreateGraph();



	return 0;
}
