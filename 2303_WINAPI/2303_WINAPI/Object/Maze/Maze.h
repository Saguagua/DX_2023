#pragma once
class Maze
{
public:
	Maze();
	~Maze();

	struct Edge
	{
		Vector2 u;
		Vector2 v;
		int cost;
	};

	void Update();
	void Render(HDC hdc);

	void CreateMaze();
	void CreateMaze_Kruskal();

	Vector2 StartPos() { return { 1,1 }; }
	Vector2 EndPos() { return Vector2((int)_mazeWidth - 2, (int)_mazeHeight - 2); }

	shared_ptr<MazeBlock> GetBlock(int x, int y) { return _blocks[y][x]; }
	int GetWidth() { return _mazeWidth; }
	int GetHeight() { return _mazeHeight; }

private:
	Vector2 frontPos[4] =
	{
		Vector2 {0, -2},  // UP
		Vector2 {-2, 0},  // LEFT
		Vector2 {0, 2},   // DOWN
		Vector2 {2, 0},   // RIGHT
	};

	vector<vector<shared_ptr<MazeBlock>>> _blocks;
	unsigned int _mazeWidth = 25;
	unsigned int _mazeHeight = 25;

	vector<Edge> edges;
};

