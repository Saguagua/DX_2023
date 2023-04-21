#include "framework.h"
#include "RectangleCollider.h"


void RectangleCollider::Update()
{}

void RectangleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_penIndex]);
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

bool RectangleCollider::IsCollision(shared_ptr<RectangleCollider> other)
{
	if (Top() > other->Bottom())
		return false;
	if (Bottom() < other->Top())
		return false;
	if (Left() > other->Right())
		return false;
	if (Right() < other->Left())
		return false;

	return true;
}

bool RectangleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector2 otherCenter = other->GetCenter();
	float otherRadius = other->GetRadius();
	if (other->GetCenter().x > Left() && other->GetCenter().x < Right()
		|| other->GetCenter().y < Bottom() && other->GetCenter().y > Top())
	{
		if (Top() - otherRadius > otherCenter.y)
			return false;
		if (Bottom() + otherRadius < otherCenter.y)
			return false;
		if (Left() - otherRadius > otherCenter.x)
			return false;
		if (Right() + otherRadius < otherCenter.x)
			return false;

		return true;
	}
	else
	{
		if (other->IsCollision(Vector2(Left(), Top())))
			return true;
		if (other->IsCollision(Vector2(Left(), Bottom())))
			return true;
		if (other->IsCollision(Vector2(Right(), Top())))
			return true;
		if (other->IsCollision(Vector2(Right(), Bottom())))
			return true;
		return false;
	}
}