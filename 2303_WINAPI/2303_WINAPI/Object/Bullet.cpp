#include "framework.h"
#include "Bullet.h"

void Bullet::Update()
{
	if (!_isActive) return;

	Move();
	_collision->SetCenter(_pos);
}

void Bullet::Render(HDC hdc)
{
	if (!_isActive) return;

	_collision->Render(hdc);
}

void Bullet::Move()
{
	_pos += _direction * _speed;
	_direction.y += GRAVITY;
	if (_pos.y < 0 || _pos.y > WIN_HEIGHT)
		_isActive = false;
	if (_pos.x < 0 || _pos.x > WIN_WIDTH)
		_isActive = false;
}

bool Bullet::AttackObject(shared_ptr<Collider> object)
{
	if (!_isActive) return false;

	if (_collision->IsCollision(object))
	{
		_isActive = false;
		return true;
	}
	return false;
}
