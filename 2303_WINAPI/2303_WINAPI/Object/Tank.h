#pragma once
class Tank
{
public:
	Tank();
	~Tank();
	void Update();
	void Render(HDC hdc);
	void Move();


private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _barrel;
	Vector2 _center = {0, 0};

	float _speed = 2.0f;

	float _barrelLength = 150.0f;
	Vector2 _barrelEnd;

};

