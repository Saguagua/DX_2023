#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	:_radius(radius)
{
	CreateVertices();
	CreateData();

	_type = Type::CIRCLE;
}

CircleCollider::~CircleCollider()
{
}

float CircleCollider::GetWorldRadius()
{
	Vector2 worldScale = _transform->GetWorldScale();

	float temp = (worldScale.x + worldScale.y) / 2;

	return _radius * temp;
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

	_vsBuffer->SetIA_VertexBuffer();
	_vsShader->SetIA_InputLayOut();

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vsShader->Set_VS();
	_psShader->Set_PS();

	DC->Draw(_vertices.size(), 0);
}

bool CircleCollider::IsCollision(Vector2 other)
{
	float len = (_transform->GetWorldPos() - other).Length();
	return len <= _radius;
}

bool CircleCollider::IsCollision(shared_ptr<class CircleCollider> other)
{
	float length = (_transform->GetWorldPos() - other->GetWorldPos()).Length();
	return length <= GetWorldRadius() + other->GetWorldRadius();
}

bool CircleCollider::IsCollision(shared_ptr<class RectCollider> other)
{
	return false;
}



void CircleCollider::CreateVertices()
{
	float p = PI / 30.0f;
	Vertex v = {};

	for (int i = 0; i < 60; i++)
	{
		v.pos = { _radius * std::cosf(p * i), _radius * std::sinf(p * i), 0.0f };

		_vertices.push_back(v);
	}

}

void CircleCollider::CreateData()
{
	_vsBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_colorBuffer = make_shared<ColorBuffer>();
	_vsShader = make_shared<VertexShader>(L"Shader/TextureVS.hlsl");
	_psShader = make_shared<PixelShader>(L"Shader/TexturePS.hlsl");
}

bool CircleCollider::Block(shared_ptr<class CircleCollider> other)
{
	if (!IsCollision(other))
		return false;

	Vector2 AtoB = other->GetWorldPos() - GetWorldPos();

	float scalar = GetWorldRadius() + other->GetWorldRadius() - AtoB.Length();

	AtoB.Normalize();

	other->AddPos(AtoB * scalar);

	return true;
}

bool CircleCollider::Block(shared_ptr<class RectCollider> other)
{

	return other->Block(shared_from_this());
}
