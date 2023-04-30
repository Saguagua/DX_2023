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
	void Move();

	bool IsActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }

	bool AttackObject(shared_ptr<Collider> object);
	
private:
	shared_ptr<Collider> _collision;
	Vector2 _pos = Vector2(300, 300);
	Vector2 _direction = Vector2();

	bool _isActive = false;
	float _speed = 2.0f;
};

