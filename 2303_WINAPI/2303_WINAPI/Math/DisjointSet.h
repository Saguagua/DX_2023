#pragma once
#include <framework.h>

class DisJointSet
{
public:
	DisJointSet(int height, int width)
	{
		_parent.resize(height);
		_rank.resize(height);

		for (int i = 0; i < height; i++)
		{
			_parent[i].reserve(width);
			_rank[i].reserve(width);
			for (int j = 0; j < width; j++)
			{
				_parent[i][j] = Vector2(j, i);
				_rank[i][j] = 1;
			}
		}
	}

	Vector2 FindLeader(Vector2 u)
	{
		if (u == _parent[u.y][u.x])
			return u;
		Vector2 parent = _parent[u.y][u.x];

		return FindLeader(parent);
	}

	void Merge(Vector2 u, Vector2 v)
	{
		Vector2 uLeader = FindLeader(u);
		Vector2 vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;
		if (_rank[vLeader.y][vLeader.x] > _rank[uLeader.y][uLeader.x])
			std::swap(uLeader, vLeader);

		_parent[vLeader.y][vLeader.x] = uLeader;

		if (_rank[uLeader.y][uLeader.x] == _rank[vLeader.y][vLeader.x])
			_rank[uLeader.y][uLeader.x]++;
	}
private:
	vector<vector<Vector2>> _parent;
	vector<vector<int>> _rank;
};
