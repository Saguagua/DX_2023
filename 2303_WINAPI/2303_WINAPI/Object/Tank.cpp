#include "framework.h"
#include "Tank.h"

Tank::Tank()
{
	_body = make_shared<CircleCollider>();
	_barrelEnd = {_center.x + _barrelLength, _center.y};
	_barrel = make_shared<Line>(_center, _barrelEnd);
}

Tank::~Tank()
{
}

void Tank::Update()
{
	Move();
}

void Tank::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Tank::Move()
{
	if (GetAsyncKeyState('A'))
	{
		_center.x -= _speed;
		//if (_center.y < _barrelEnd.y)
			
		
	}
	if (GetAsyncKeyState('D'))
	{
		_center.x += _speed;
	}
	if (GetAsyncKeyState('W'))
	{
		_center.y -= _speed;
	}
	if (GetAsyncKeyState('S'))
	{
		_center.y += _speed;
	}

	_body->SetCenter(_center);

}

