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

RectCollider::AABB_Info RectCollider::GetAABB_Info()
{
	AABB_Info info = {};
	info.left = _transform->GetWorldPos().x - _size.x * _transform->GetWorldScale().x * 0.5f;
	info.right = _transform->GetWorldPos().x + _size.x * _transform->GetWorldScale().x * 0.5f;
	info.top = _transform->GetWorldPos().y + _size.y * _transform->GetWorldScale().y * 0.5f;
	info.bottom = _transform->GetWorldPos().y - _size.y * _transform->GetWorldScale().y * 0.5f;
	
	return info;
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
	AABB_Info info = GetAABB_Info();
	Vector2 circlePos = other->GetWorldPos();
	float radius = other->GetWorldRadius();

	float top = circlePos.y + radius;
	float bottom = circlePos.y - radius;
	float left = circlePos.x - radius;
	float right = circlePos.x + radius;

	if (circlePos.x < info.right && circlePos.x > info.left)
	{
		if (bottom < info.top && top > info.bottom)
		{
			return true;
		}
	}

	if (circlePos.y > info.bottom && circlePos.y < info.top)
	{
		if (left < info.right && right > info.left)
		{
			return true;
		}
	}

	if (other->IsCollision(Vector2(info.left, info.top))
		|| other->IsCollision(Vector2(info.right, info.top))
		|| other->IsCollision(Vector2(info.left, info.bottom))
		|| other->IsCollision(Vector2(info.right, info.bottom)))
	{
		return true;
	}

	return false;
}

bool RectCollider::IsCollision(shared_ptr<class RectCollider> other)
{
	AABB_Info myInfo = GetAABB_Info();
	AABB_Info otherInfo = other->GetAABB_Info();

	if (myInfo.left > otherInfo.right
	|| myInfo.right < otherInfo.left
	|| myInfo.top < otherInfo.bottom
	|| myInfo.bottom > otherInfo.top)
		return false;

	return true;
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