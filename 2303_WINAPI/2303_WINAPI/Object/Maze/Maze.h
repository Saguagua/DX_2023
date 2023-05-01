#pragma once
class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze();

	Vector2 StartPos() { return { 1,1 }; }
	Vector2 EndPos() { return Vector2((int)_mazeWidth - 2, (int)_mazeHeight - 2); }

	shared_ptr<MazeBlock> GetBlock(int x, int y) { return _blocks[y][x]; }
	int GetWidth() { return _mazeWidth; }
	int GetHeight() { return _mazeHeight; }

private:
	vector<vector<shared_ptr<MazeBlock>>> _blocks;
	unsigned int _mazeWidth = 25;
	unsigned int _mazeHeight = 25;
};

