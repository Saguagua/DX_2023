#pragma once
class Bullet
{
public:
	Bullet() { _collision = make_shared<CircleCollider>(30, _pos); }
	~Bullet() {}

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector2 pos) { _pos = pos; }
	void SetDirection(Vector2 direction) { _direction = direction; }
	void Move() { _pos += _direction.Unit() * _speed; }
private:
	shared_ptr<CircleCollider> _collision;
	Vector2 _pos = Vector2(300, 300);
	Vector2 _direction = Vector2();

	float _speed = 20.0f;
};

