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
	return 0.0f;
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
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<class CircleCollider> other)
{
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<class RectCollider> other)
{
	return false;
}

void CircleCollider::CreateVertices()
{
	float p = PI / 30;
	Vertex v = {};

	for (int i = 0; i < 60; i++)
	{
		v.pos = {_radius * std::cosf(p*i), _radius * std::sinf(p*i), 0.0f};
		
		_vertices.push_back(v);
	}
	
}

void CircleCollider::CreateData()
{
	_vsBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_colorBuffer = make_shared<ColorBuffer>();
	_vsShader = make_shared<VertexShader>(L"Shader/VertexShader.hlsl");
	_psShader = make_shared<PixelShader>(L"Shader/PixelShader.hlsl");
}