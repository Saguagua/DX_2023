#include "framework.h"
#include "Collider.h"

bool Collider::IsCollision(shared_ptr<Collider> other)
{
	switch (other->_type)
	{
	case (Collider::Type::NORMAL):
		return false;
	case (Collider::Type::CIRCLE):
		return IsCollision(dynamic_pointer_cast<CircleCollider>(other));
	case (Collider::Type::RECANGLE):
		return IsCollision(dynamic_pointer_cast<RectangleCollider>(other));
	default:
		break;
	}

	return false;
}

void Collider::CreatePens()
{
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));
}