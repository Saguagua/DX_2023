#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_world = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::Update()
{
	Update_SRT();
	Update_World();
}

void Transform::Update_SRT()
{
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, 1.0f);
	XMMATRIX rotate = XMMatrixRotationZ(_angle);
	XMMATRIX translate = XMMatrixTranslation(_pos.x, _pos.y, 0.0f);
	
	_srt = scale * rotate * translate;
	
	if (!_parent.expired())
	{
		_srt *= _parent.lock()->GetSRT();
	}
}

void Transform::Update_World()
{
	_world->SetData(_srt);
	_world->Update_Resource();
}

void Transform::Set_World(UINT slot)
{
	_world->SetVS_Buffer(slot);
}

void Transform::SetParent(shared_ptr<Transform> other)
{
	_parent = other;
}

Vector2 Transform::GetScale()
{
	return _scale;
}

float Transform::GetAngle()
{
	return _angle;
}

Vector2 Transform::GetPos()
{
	return _pos;
}

void Transform::SetScale(Vector2 scale)
{
	_scale = scale;
}

void Transform::SetRotate(float angle)
{
	_angle = angle;
}

void Transform::SetPos(Vector2 pos)
{
	_pos = pos;
}

Vector2 Transform::GetWorldPos()
{
	XMFLOAT4X4 tmp;
	
	XMStoreFloat4x4(&tmp, _srt);

	return Vector2(tmp._41, tmp._42);
}

Vector2 Transform::GetWorldScale()
{

	XMFLOAT4X4 temp;

	XMStoreFloat4x4(&temp, _srt);

	if (_parent.expired() == false)
	{
		Vector2 parentScale = _parent.lock()->GetWorldScale();

		return Vector2(temp._11 * parentScale.x, temp._22 * parentScale.y);
	}

	return Vector2(temp._11, temp._22);

}

XMMATRIX Transform::GetSRT()
{
	return _srt;
}
