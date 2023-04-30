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
	vector<shared_ptr<Bullet>> GetBullets() { return _bullets; }
	shared_ptr<Bullet> SetBullet();

private:
	
	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _barrel;
	Vector2 _center = {200, 300};

	float _speed = 1.0f;
	float _angle = 0.0f;

	bool _spacePress = true;
	bool _spaceUp = false;

	float _barrelLength = 150.0f;
	Vector2 _barrelUnit;

	Vector2 direction = _center;
	vector<shared_ptr<Bullet>> _bullets;

};