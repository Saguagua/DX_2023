#pragma once
class Line
{
public:
	Line(Vector2 start, Vector2 end) :_startPos(start), _endPos(end) {}
	~Line() {};

	void Update() {};
	void Render(HDC hdc) 
	{
		MoveToEx(hdc, _startPos.x, _startPos.y, nullptr);
		LineTo(hdc, _endPos.x, _endPos.y);
	};

public:
	Vector2 _startPos;
	Vector2 _endPos;
};

