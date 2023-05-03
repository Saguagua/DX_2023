#pragma once
class Player
{
public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();

	void BFS(Vector2 startPos);
	void DFS(Vector2 startPos);
	void Dijkstra(Vector2 startPos);

	bool Cango(Vector2 pos);
private:
	weak_ptr<Maze> _maze;
	Vector2 _startPos = {1, 1};
	Vector2 _endPos = {1, 1};

	float _time = 0.0f;

	vector<Vector2> _path;
	int _pathIndex = 0;
	stack<Vector2> _stack;

	struct Vertex
	{
		int cost;
		Vector2 vertexNum;

		bool operator<(const Vertex other) const
		{
			return cost < other.cost;
		}

		bool operator>(const Vertex other) const
		{
			return cost > other.cost;
		}
	};

	vector<vector<int>> _best;
	vector<vector<bool>> _discovered;
	vector<vector<Vector2>> _parent;
	vector<Vector2> _shortCut;

	Vector2 frontPos[8] =
	{
		Vector2 {0, -1},  // UP
		Vector2 {-1, 0},  // LEFT
		Vector2 {0, 1},   // DOWN
		Vector2 {1, 0},   // RIGHT
		Vector2 {-1, -1}, // UPRIGHT
		Vector2 {-1, 1},  // UPLEFT
		Vector2 {1, -1},  // DOWNLEFT
		Vector2 {1, 1}    // DOWNRIGHT
	};
};

