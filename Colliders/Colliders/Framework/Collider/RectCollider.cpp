#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
	:_size(size)
{
	CreateVertices();
	CreateData();

	_type = Type::RECT;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
	_transform->Update();
	_colorBuffer->SetColor(_color);
	_colorBuffer->Update_Resource();
}

void RectCollider::Render()
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

bool RectCollider::IsCollision(Vector2 other)
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<class CircleCollider> other)
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<class RectCollider> other)
{
	return false;
}

void RectCollider::CreateVertices()
{
	Vertex v = {};

	Vector2 halfSize = _size * 0.5f;

	v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
	_vertices.push_back(v);

	v.pos = { halfSize.x, halfSize.y, 0.0f }; // 오른쪽 위
	_vertices.push_back(v);

	v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
	_vertices.push_back(v);

	v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
	_vertices.push_back(v);

	v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
	_vertices.push_back(v);
}

void RectCollider::CreateData()
{
	_vsBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_colorBuffer = make_shared<ColorBuffer>();

	_vsShader = make_shared<VertexShader>(L"Shader/VertexShader.hlsl");
	_psShader = make_shared<PixelShader>(L"Shader/PixelShader.hlsl");
}