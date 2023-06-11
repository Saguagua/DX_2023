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

RectCollider::OBB_Info RectCollider::GetOBB_Info()
{
	OBB_Info info = {};
	info.pos = _transform->GetWorldPos();
	
	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, _transform->GetSRT());

	info.direction[0] = {matrix._11, matrix._12};
	info.direction[1] = {matrix._21, matrix._22};
	
	info.direction[0].Normalize();
	info.direction[1].Normalize();

	Vector2 scale = _transform->GetWorldScale();

	info.length[0] = _size.x * 0.5f * scale.x;
	info.length[1] = _size.y * 0.5f * scale.y;
	
	return info;
}

float RectCollider::SeperateAxis(Vector2 seperate, Vector2 eb1, Vector2 eb2)
{
	 float r1 = abs(seperate.Dot(eb1));
	 float r2 = abs(seperate.Dot(eb2));
	return r1 + r2;
}

bool RectCollider::Block(shared_ptr<class CircleCollider> other)
{
	if (!IsCollision(other))
		return false;
	Vector2 AtoB = other->GetWorldPos() - GetWorldPos();

	AABB_Info info = GetAABB_Info();
	float circleRadius = other->GetWorldRadius();

	Vector2 mySize = Vector2();
	mySize.x = (info.right - info.left) * 0.5f;
	mySize.y = (info.top - info.bottom) * 0.5f;

	Vector2 overlap = Vector2();
	overlap.x = mySize.x + circleRadius - abs(AtoB.x);
	overlap.y = mySize.y + circleRadius - abs(AtoB.y);

	if (overlap.x > overlap.y)
	{
		AtoB.Normalize();
		//Vector2 tmp = Vector2(0, );
		other->AddPos(AtoB * overlap.y);
	}
	else
	{
		AtoB.Normalize();
		other->AddPos(AtoB * overlap.x);
	}

	return true;
}

bool RectCollider::Block(shared_ptr<class RectCollider> other)
{
	if (!IsCollision(other))
		return false;

	AABB_Info myInfo = GetAABB_Info();
	AABB_Info otherInfo = other->GetAABB_Info();

	Vector2 AtoB = other->GetWorldPos() - GetWorldPos();
	
	Vector2 mySize = Vector2((myInfo.right - myInfo.left) * 0.5f, (myInfo.top - myInfo.bottom) * 0.5f);
	Vector2 otherSize = Vector2((otherInfo.right - otherInfo.left) * 0.5f, (otherInfo.top - otherInfo.bottom) * 0.5f);
	Vector2 overlap = Vector2(mySize.x + otherSize.x - abs(AtoB.x), mySize.y + otherSize.y - abs(AtoB.y));
	
	if (overlap.x > overlap.y)
	{
		AtoB.Normalize();
		Vector2 tmp = Vector2(0.0f, overlap.y * AtoB.y);
		other->AddPos(tmp);
	}
	else
	{
		AtoB.Normalize();
		Vector2 tmp = Vector2(overlap.x * AtoB.x, 0.0f);
		other->AddPos(tmp);
	}

	return true;
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

bool RectCollider::IsOBB(shared_ptr<CircleCollider> other)
{
	OBB_Info aInfo = GetOBB_Info();
	float circleRadius = other->GetWorldRadius();
	Vector2 circlePos = other->GetWorldPos();

	Vector2 AtoB = aInfo.pos - circlePos;
	Vector2 ne1 = aInfo.direction[0];
	Vector2 ne2 = aInfo.direction[1];
	Vector2 e1 = ne1 * aInfo.length[0];
	Vector2 e2 = ne2 * aInfo.length[1];

	float length = abs(AtoB.Dot(ne1));
	float lengthA = SeperateAxis(ne1, e1, e2);
	
	if (length > lengthA + circleRadius)
		return false;

	length = abs(AtoB.Dot(ne2));
	lengthA = SeperateAxis(ne2, e1, e2);

	if (length > lengthA + circleRadius)
		return false;

	return true;
}

bool RectCollider::IsOBB(shared_ptr<RectCollider> other)
{
	OBB_Info aInfo = GetOBB_Info();
	OBB_Info bInfo = other->GetOBB_Info();

	Vector2 nea1 = aInfo.direction[0];
	Vector2 nea2 = aInfo.direction[1];
	Vector2 neb1 = bInfo.direction[0];
	Vector2 neb2 = bInfo.direction[1];

	Vector2 ea1 = nea1 * aInfo.length[0];
	Vector2 ea2 = nea2 * aInfo.length[1];
	Vector2 eb1 = neb1 * bInfo.length[0];
	Vector2 eb2 = neb2 * bInfo.length[1];

	Vector2 AtoB = aInfo.pos - bInfo.pos;
	
	float length = abs(nea1.Dot(AtoB));
	float lengthA = ea1.Length();
	float lengthB = SeperateAxis(nea1, eb1, eb2);
	
	if (length > lengthA + lengthB)
		return false;

	length = abs(nea2.Dot(AtoB));
	lengthA = ea2.Length();
	lengthB = SeperateAxis(nea2, eb1, eb2);

	if (length > lengthA + lengthB)
		return false;

	length = abs(neb1.Dot(AtoB));
	lengthA = eb1.Length();
	lengthB = SeperateAxis(neb1, ea1, ea2);

	if (length > lengthA + lengthB)
		return false;

	length = abs(neb2.Dot(AtoB));
	lengthA = eb2.Length();
	lengthB = SeperateAxis(neb2, ea1, ea2);

	if (length > lengthA + lengthB)
		return false;

	return true;
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