#include "framework.h"
#include "Bullet.h"

void Bullet::Update()
{
	Move();
	_collision->SetCenter(_pos);
}

void Bullet::Render(HDC hdc)
{
	_collision->Render(hdc);
}
