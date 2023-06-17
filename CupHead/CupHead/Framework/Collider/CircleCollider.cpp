#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
    : _radius(radius)
{
    CreateVertices();
    CreateData();

    _type = Type::CIRCLE;
}

void CircleCollider::Update()
{
    _transform->Update();

    _colorBuffer->SetColor(_color);
    _colorBuffer->Update_Resource();
}

void CircleCollider::Render()
{
    _transform->Set_World(0);
    _colorBuffer->SetPS_Buffer(0);

    _vertexBuffer->SetIA_VertexBuffer();
    _vs.lock()->SetIA_InputLayout();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs.lock()->Set();
    _ps.lock()->Set();

    DC->Draw(_vertices.size(), 0);
}

void CircleCollider::CreateVertices()
{
    Vertex v;

    for (int i = 0; i < 37; i++)
    {
        v.pos = { _radius * cosf(i * PI / 18.0f), _radius * sinf(i * PI / 18.0f), 0.0f };
        _vertices.push_back(v);
    }
}

void CircleCollider::CreateData()
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _vs = ADD_VS(L"Shader/VertexVS.hlsl");
    _ps = ADD_PS(L"Shader/SingleColorPS.hlsl");
}

bool CircleCollider::IsCollision(const Vector2& pos)
{
    float distance = GetWorldPos().Distance(pos);
    if (distance < GetWorldRadius())
        return true;
    return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> col)
{
    float distance = GetWorldPos().Distance(col->GetWorldPos());
    if (distance < GetWorldRadius() + col->GetWorldRadius())
        return true;
    return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> col)
{
    return col->IsCollision(shared_from_this());
}

bool CircleCollider::Block(shared_ptr<CircleCollider> col)
{
    if (!IsCollision(col))
        return false;

    Vector2 aPos = GetWorldPos();
    Vector2 bPos = col->GetWorldPos();

    float aRadius = GetWorldRadius();
    float bRadius = col->GetWorldRadius();

    Vector2 dir = bPos - aPos;

    float scalar = (aRadius + bRadius) - dir.Length();

    dir.Normalize();

    Vector2 pushVector = dir * scalar;

    bPos = bPos + pushVector;
    col->GetTransform()->SetPos(bPos);

    return true;
}

float CircleCollider::GetWorldRadius()
{
    Vector2 worldScale = _transform->GetWorldScale();

    float temp = (worldScale.x + worldScale.y) / 2;

    return _radius * temp;
}
