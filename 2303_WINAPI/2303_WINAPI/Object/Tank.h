#pragma once
class Tank
{
public:
	Tank();
	~Tank();
	void Update();
	void Render(HDC hdc);
	void Move();
	void Fire();

private:
	
	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _barrel;
	Vector2 _center = {200, 300};

	float _speed = 2.0f;
	float _angle = 0.0f;

	float _barrelLength = 150.0f;
	Vector2 _barrelUnit;

	Vector2 direction = _center;

	shared_ptr<Bullet> _bullet;
};

