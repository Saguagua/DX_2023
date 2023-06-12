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
	_scaleM = XMMatrixScaling(_scale.x, _scale.y, 1.0f);
	_rotateM = XMMatrixRotationZ(_angle);
	_translateM = XMMatrixTranslation(_pos.x, _pos.y, 0.0f);

	_srt = _scaleM * _rotateM * _translateM;

	if (!_parent.expired())
	{
		_srt *= _parent.lock()->GetSRT();
	}
}

void Transform::Update_World()
{
	_world->SetData(_srt);
	_world->UpdateData();
}

void Transform::SetWorld(UINT slot)
{
	_world->SetVS_Buffer(slot);
}

Vector2 Transform::GetWorldPos()
{
	XMFLOAT4X4 tmp;

	XMStoreFloat4x4(&tmp, _srt);

	return Vector2(tmp._41, tmp._42);
}

Vector2 Transform::GetWorldScale()
{
	XMFLOAT4X4 tmp;
	
	XMStoreFloat4x4(&tmp, _scaleM);

	if (_parent.expired() == false)
	{
		Vector2 parentScale = _parent.lock()->GetWorldScale();

		return Vector2(tmp._11 * parentScale.x, tmp._22 * parentScale.y);
	}

	return Vector2(tmp._11, tmp._22);
}

XMMATRIX Transform::GetSRT()
{
	return _srt;
}
