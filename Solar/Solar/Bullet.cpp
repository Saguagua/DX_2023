#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Bullet");
	_trans = make_shared<Transform>();
	_direction = { 0,0 };
}

Bullet::~Bullet()
{
}

void Bullet::Render()
{
	if (!_isActive)
		return;
	_quad->Render();
}

void Bullet::Update()
{
	if (!_isActive)
		return;
	_trans->AddVector2(_direction);
	_quad->Update();
}

void Bullet::Shoot()
{
	if (_isActive)
		return;
	_direction = _trans->GetWorldPos() - Vector2(100, 100);
	_direction.Normalize();
	_isActive = true;
	//_trans->SetPosition();
}
