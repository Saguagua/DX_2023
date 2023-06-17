#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
    _world = make_shared<MatrixBuffer>();
}

void Transform::Update()
{
    Update_SRT();
    Update_World();
}

void Transform::Update_SRT()
{
    _scaleM = XMMatrixScaling(_scale.x, _scale.y, 1.0f);
    _rotateM = XMMatrixRotationZ(_rotate);
    _translateM = XMMatrixTranslation(_translate.x, _translate.y, 0.0f);

    _srt = _scaleM * _rotateM * _translateM;

    if (!_parent.expired())
    {
        _srt *= _parent.lock()->GetSRT();
    }
}

void Transform::Set_World(UINT slot)
{
    _world->SetVS_Buffer(slot);
}

const Vector2& Transform::GetWorldPos()
{
    XMFLOAT4X4 tmp;

    XMStoreFloat4x4(&tmp, _scaleM);

    return Vector2(tmp._41, tmp._42);
}

const Vector2& Transform::GetWorldScale()
{
    XMFLOAT4X4 tmp;

    XMStoreFloat4x4(&tmp, _srt);

    if (!_parent.expired())
    {
        Vector2 parentScale = _parent.lock()->GetWorldScale();
        return Vector2(tmp._11 * parentScale.x, tmp._22 * parentScale.y);
    }

    return Vector2(tmp._11, tmp._22);
}

void Transform::Update_World()
{
    _world->SetMatrix(_srt);
    _world->Update_Resource();
}

