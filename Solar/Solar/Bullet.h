#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Render();
	void Update();

	void Shoot();
private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _trans;
	Vector2 _direction;

	bool _isActive = false;
};

