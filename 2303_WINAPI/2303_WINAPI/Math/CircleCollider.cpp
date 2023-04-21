#include "framework.h"
#include "CircleCollider.h"


void CircleCollider::Update()
{}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_penIndex]);

	float left = _center.x - _radius;
	float right = _center.x + _radius;
	float top = _center.y - _radius;
	float bottom = _center.y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 other)
{
	return _radius > _center.Distance(other);
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return _radius + other->GetRadius() > _center.Distance(other->GetCenter());
}

bool CircleCollider::IsCollision(shared_ptr<RectangleCollider> other)
{
	return other->IsCollision(shared_from_this());
}