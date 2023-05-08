#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent.resize(n);
		_rank.resize(n, 1);

		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;
		int parent = _parent[u];

		return FindLeader(parent);
	}

	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;
		if (_rank[vLeader] > _rank[uLeader])
			std::swap(uLeader, vLeader);

		_parent[vLeader] = uLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[uLeader]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

vector<vector<int>> adjacent;

struct Edge
{
	int vertexU;
	int vertexV;
	int cost;
};

vector<Edge> edges;

void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 4;
	adjacent[0][2] = 1;
	adjacent[0][4] = 8;

	adjacent[1][0] = 4;
	adjacent[1][1] = 0;
	adjacent[1][6] = 7;
	adjacent[1][2] = 2;

	adjacent[2][0] = 1;
	adjacent[2][1] = 2;
	adjacent[2][2] = 0;
	adjacent[2][3] = 4;
	adjacent[2][5] = 5;

	adjacent[3][3] = 0;
	adjacent[3][2] = 4;

	adjacent[4][0] = 8;
	adjacent[4][4] = 0;

	adjacent[5][2] = 5;
	adjacent[5][5] = 0;
	adjacent[5][6] = 80;

	adjacent[6][1] = 7;
	adjacent[6][5] = 80;
	adjacent[6][6] = 0;

	for (int i = 0; i < adjacent.size(); i++)
	{
		for (int j = 0; j < adjacent[i].size(); j++)
		{
			if (i == j)
				continue;

			if (adjacent[i][j] == -1)
				continue;

			Edge edge;
			edge.vertexU = i;
			edge.vertexV = j;
			edge.cost = adjacent[i][j];
			edges.push_back(edge);
		}
	}
}

vector<Edge> Kruskal()
{
	vector<Edge> result;

	std::sort(edges.begin(), edges.end(), 
	[](const Edge& a, const Edge& b)-> bool
	{
		return a.cost < b.cost;
	}
	);

	DisJointSet sets(adjacent.size());

	for (auto edge : edges)
	{
		if (sets.FindLeader(edge.vertexU) == sets.FindLeader(edge.vertexV))
			continue;

		sets.Merge(edge.vertexU, edge.vertexV);
		result.push_back(edge);
	}

	return result;
}
 
int main()
{
	CreateGraph();
	auto result = Kruskal();

	return 0;
}