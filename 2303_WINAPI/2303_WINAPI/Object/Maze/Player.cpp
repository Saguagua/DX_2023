#include "framework.h"
#include "Player.h"

Player::Player(shared_ptr<Maze> maze)
	:_maze(maze)
{
	if (!_maze.expired())
	{
		_startPos = _maze.lock()->StartPos();
		_endPos = _maze.lock()->EndPos();
		_maze.lock()->GetBlock(_startPos.x, _startPos.y)->SetType(MazeBlock::BlockType::PLAYER);
		
		int height = _maze.lock()->GetHeight();
		int width = _maze.lock()->GetWidth();
		_discovered = vector<vector<bool>>(height, vector<bool>(width, false));
		_parent = vector<vector<Vector2>>(height, vector<Vector2>(width, Vector2(-1, -1)));
		_best = vector<vector<int>>(height, vector<int>(width, INT_MAX));

		Dijkstra(_startPos);
	}
}

Player::~Player()
{
}

void Player::Update()
{
	_time += 0.4f;
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pathIndex++;
	}
	if (_pathIndex < _path.size())
	{
		if (_pathIndex > 0)
		{
			Vector2 pos = _path[_pathIndex - 1];
			_maze.lock()->GetBlock(pos.x, pos.y)->SetType(MazeBlock::BlockType::PLAYER);
		}

		Vector2 pos = _path[_pathIndex];
		_maze.lock()->GetBlock(pos.x, pos.y)->SetType(MazeBlock::BlockType::CURRENT);
	}
	else 
	{
		if (_stack.empty())
			return;
		Vector2 pos = _stack.top();
		_stack.pop();
		_maze.lock()->GetBlock(pos.x, pos.y)->SetType(MazeBlock::BlockType::SHORTCUT);
	}
}

void Player::BFS(Vector2 startPos)
{
	_discovered[_startPos.y][_startPos.x] = true;
	_parent[_startPos.y][_startPos.x] = Vector2(_startPos.x, _startPos.y);

	queue<Vector2> q;
	q.push(startPos);
	_path.push_back(startPos);

	while (true)
	{
		if (q.empty()) break;
		if (_path.size() > 1 && _path[_path.size() - 1] == _endPos) break;
		Vector2 pos = q.front();
		q.pop();
		Vector2 newDirection;

		for (int i = 0; i < 4; i++)
		{
			newDirection = pos + frontPos[i];

			if (_discovered[newDirection.y][newDirection.x])
				continue;

			if (!Cango(newDirection))
				continue;

			q.push(newDirection);
			_discovered[newDirection.y][newDirection.x] = true;
			_parent[newDirection.y][newDirection.x] = pos;
			_path.push_back(newDirection);
		}
	}

	Vector2 direction = _endPos;
	while (true)
	{
		if (direction == _parent[direction.y][direction.x]) break;
		direction = _parent[direction.y][direction.x];
		_maze.lock()->GetBlock(direction.x, direction.y)->SetType(MazeBlock::BlockType::SHORTCUT);
	}
}

void Player::DFS(Vector2 startPos)
{
	_discovered[startPos.y][startPos.x] = true;
	if (startPos == _endPos) return;
	
	for (int i = 0; i < 4; i++)
	{
		Vector2 newDirection = startPos + frontPos[i];
		if (_discovered[newDirection.y][newDirection.x])
			continue;
		if (Cango(newDirection))
		{
			_path.push_back(newDirection);
			DFS(newDirection);
		}
	}
}

void Player::Dijkstra(Vector2 startPos)
{
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	Vertex start;
	start.cost = 0;
	start.vertexNum = startPos;

	_best[startPos.y][startPos.x] = start.cost;
	_parent[startPos.y][startPos.x] = startPos;

	pq.push(start);

	while (true)
	{
		if (pq.empty() || _endPos == pq.top().vertexNum)
			break;

		int nowCost = pq.top().cost;
		Vector2 nowNum = pq.top().vertexNum;

		pq.pop();

		if (nowCost > _best[nowNum.y][nowNum.x])
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector2 newNum = nowNum + frontPos[i];
			if (Cango(newNum))
			{
				int newCost = _best[nowNum.y][nowNum.x] + 10;

				if (frontPos[i].x != 0 && frontPos[i].y != 0)
					newCost += 4;

				if (newCost >= _best[newNum.y][newNum.x])
					continue;

				_parent[newNum.y][newNum.x] = nowNum;
				_best[newNum.y][newNum.x] = newCost;
				Vertex newVertex;
				newVertex.cost = newCost;
				newVertex.vertexNum = newNum;

				pq.push(newVertex);
				_path.push_back(newNum);
			}
		}
	}
	Vector2 root = _parent[_endPos.y][_endPos.x];
	
	_stack.push(_endPos);
	while (true)
	{
		if (root == _parent[root.y][root.x])
			break;
		_stack.push(root);
		root = _parent[root.y][root.x];
	}
}

bool Player::Cango(Vector2 pos)
{
	MazeBlock::BlockType type = _maze.lock()->GetBlock(pos.x, pos.y)->GetType();
	if (type == MazeBlock::BlockType::DISABLE)
		return false;
	if (type == MazeBlock::BlockType::NONE)
		return false;

	return true;
}
