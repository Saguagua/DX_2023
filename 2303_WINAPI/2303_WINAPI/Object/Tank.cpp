#include "framework.h"
#include "Tank.h"

Tank::Tank()
{
	_body = make_shared<CircleCollider>(50, _center);
	_barrel = make_shared<Line>(_center, _center + Vector2(_barrelLength, 0.0f));
	_barrelUnit = (_barrel->_endPos - _barrel->_startPos).Unit();
	for (int i = 0; i < 30; i++)
		_bullets.push_back(make_shared<Bullet>());
}

Tank::~Tank()
{
}

void Tank::Update()
{
	Move();
	_body->SetCenter(_center);
	_barrel->_startPos = _center;
	_barrel->_endPos = _center + (_barrelUnit * _barrelLength);
	Fire();
	for (auto bullet : _bullets)
		bullet->Update();
}

void Tank::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
		bullet->Render(hdc);
}

void Tank::Move()
{
	if (GetAsyncKeyState('A'))
	{
		direction.x -= _speed;
	}
	if (GetAsyncKeyState('D'))
	{
		direction.x += _speed;
	}
	if (GetAsyncKeyState('W'))
	{
		direction.y -= _speed;
	}
	if (GetAsyncKeyState('S'))
	{
		direction.y += _speed;
	}
	
	Vector2 currentDirection = direction - _center;
	_center = direction;
	if (currentDirection.x == 0 && currentDirection.y == 0) return;

	float dot = currentDirection.Unit().Dot(_barrelUnit);
	float error = dot - (_barrelUnit.Length() * _barrelUnit.Length());
	if (error < 0.001f && error > -0.001f) return;
	else if (error > 0)
		_angle -= 0.05f;
	else if (error < 0)
		_angle += 0.05f;
	
	_barrelUnit.x = cos(_angle);
	_barrelUnit.y = sin(_angle);
}

void Tank::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		_spacePress = true;
		_spaceUp = false;
	}
	else
		_spaceUp = true;

	if (_spacePress && _spaceUp)
	{
		shared_ptr<Bullet> bullet = SetBullet();
		if (bullet == nullptr) return;
		bullet->SetPos(_barrel->_endPos);
		bullet->SetDirection(_barrelUnit);

		_spacePress = false;
		_spaceUp = false;
	}
}

shared_ptr<Bullet> Tank::SetBullet()
{
	for (auto bullet : _bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->SetActive(true);
			return bullet;
		}
	}

	return nullptr;
}