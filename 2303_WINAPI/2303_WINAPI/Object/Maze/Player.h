#pragma once
class Player
{
public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();
private:
	weak_ptr<Maze> _maze;
	Vector2 _startPos = {1, 1};
	Vector2 _endPos = {1, 1};
};

