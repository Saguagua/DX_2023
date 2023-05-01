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
		BFS(_startPos);
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
	if (_pathIndex >= _path.size())
		return;

	if (_pathIndex > 0)
	{
		Vector2 pos = _path[_pathIndex - 1];
		_maze.lock()->GetBlock(pos.x, pos.y)->SetType(MazeBlock::BlockType::PLAYER);
	}
	
	Vector2 pos = _path[_pathIndex];
	_maze.lock()->GetBlock(pos.x, pos.y)->SetType(MazeBlock::BlockType::CURRENT);
}

void Player::BFS(Vector2 startPos)
{
	int height = _maze.lock()->GetHeight();
	int width = _maze.lock()->GetHeight();

	_discovered = vector<vector<bool>>(height, vector<bool>(width, false));
	_parent = vector<vector<Vector2>>(height, vector<Vector2>(width, Vector2(-1, -1)));

	_discovered[_startPos.y][_startPos.x] = true;
	_parent[_startPos.y][_startPos.x] = Vector2(_startPos.x, _startPos.y);

	queue<Vector2> q;
	q.push(startPos);
	_path.push_back(startPos);

	Vector2 frontPos[4] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0} // RIGHT
	};

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

bool Player::Cango(Vector2 pos)
{
	MazeBlock::BlockType type = _maze.lock()->GetBlock(pos.x, pos.y)->GetType();
	if (type == MazeBlock::BlockType::DISABLE)
		return false;
	if (type == MazeBlock::BlockType::NONE)
		return false;

	return true;
}
