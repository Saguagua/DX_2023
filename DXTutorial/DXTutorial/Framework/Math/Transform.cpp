#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_world = make_shared<MatrixBuffer>();
	_srt = XMMatrixIdentity();
}

Transform::~Transform()
{
}

void Transform::SetBuffer(UINT slot)
{
	_world->SetVS_Buffer(slot);
}

void Transform::UpdateBuffer()
{
	_world->SetData(_srt);
	_world->Update_Resource();
}

void Transform::UpdateSRT()
{
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, 1.0f);
	XMMATRIX angle = XMMatrixRotationZ(_angle);
	XMMATRIX trans = XMMatrixTranslation(_pos.x, _pos.y, 0.0f);

	_srt = scale * angle * trans;
}

void Transform::AddPos(Vector2<float> pos)
{
	_pos += pos;
}

void Transform::AddScale(Vector2<float> scale)
{
	_scale += scale;
}

void Transform::AddAngle(float angle)
{
	_angle += angle;
}

void Transform::SetPos(Vector2<float> pos)
{
	_pos = pos;
}

void Transform::SetScale(Vector2<float> scale)
{
	_scale = scale;
}

void Transform::SetAngle(float angle)
{
	_angle = angle;
}
