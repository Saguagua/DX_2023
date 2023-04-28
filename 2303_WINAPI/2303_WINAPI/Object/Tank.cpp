#include "framework.h"
#include "Tank.h"

Tank::Tank()
{
	_body = make_shared<CircleCollider>(50, _center);
	_barrel = make_shared<Line>(_center, _center + Vector2(_barrelLength, 0.0f));
	_barrelUnit = (_barrel->_endPos - _barrel->_startPos).Unit();
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
}

void Tank::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Tank::Move()
{
	
	Vector2 direction = _center;

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

	Vector2 current = direction - _center;
	Vector2 barrel = _barrel->_endPos - _barrel->_startPos;
	float dot = current.Dot(barrel);
	float length = current.Length() * barrel.Length();
	if (length == 0) return;

	float cosine = dot / length;
	_center = direction;
	float ceta = acos(cosine);

	if (ceta == 0.0f)
		return;
	else
		_angle -= 0.01f;
	
	_barrelUnit.x = cos(_angle);
	_barrelUnit.y = sin(_angle);
}