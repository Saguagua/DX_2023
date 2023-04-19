#include "framework.h"
#include "CircleCollider.h"

void CircleCollider::Update()
{
	_center;
}

void CircleCollider::Render(HDC hdc)
{
	Ellipse(hdc, _center.x-_radius, _center.y-_radius, _center.x+_radius, _center.y+_radius);
}
