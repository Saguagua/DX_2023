#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
	_transform = make_shared<Transform>();
}

Collider::~Collider()
{
}

void Collider::SetColor(XMFLOAT4 color)
{
	_color = color;
}

void Collider::SetPos(Vector2 pos)
{
	_transform->SetPos(pos);
}

void Collider::SetAngle(float angle)
{
	_transform->SetRotate(angle);
}

Vector2 Collider::GetWorldPos()
{
	return _transform->GetWorldPos();
}

Vector2 Collider::GetWorldScale()
{
	return _transform->GetScale();
}

bool Collider::IsCollision(shared_ptr<Collider> other)
{
	switch (other->_type)
	{
	case Collider::Type::NONE:
		return false;
	case Collider::Type::CIRCLE:
		return IsCollision(dynamic_pointer_cast<CircleCollider>(other));
	case Collider::Type::RECT:
		return IsCollision(dynamic_pointer_cast<RectCollider>(other));
	default:
		return false;
	}
}
