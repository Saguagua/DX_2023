#pragma once

#include "../../Types.h"

class RectCollider;
class CircleCollider;

class Collider
{
public:
	Collider();
	virtual ~Collider() {}

	virtual void Update() abstract;
	virtual void Render() abstract;

	bool IsCollision(shared_ptr<Collider> col);
	virtual bool IsCollision(const Vector2& pos) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> col) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> col) abstract;

	void SetColorRed() { _color = RED; }
	void SetColorGreen() { _color = GREEN; }

	shared_ptr<Transform> GetTransform() { return _transform; }
	Vector2 GetWorldPos() { return _transform->GetWorldPos(); }

protected:
	virtual void CreateVertices() abstract;
	virtual void CreateData() abstract;

	enum class Type
	{
		NONE,
		CIRCLE,
		RECT
	};

	Type _type = Type::NONE;
	XMFLOAT4 _color = GREEN;
	shared_ptr<Transform> _transform;

	vector<Vertex> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<ColorBuffer> _colorBuffer;

	weak_ptr<VertexShader> _vs;
	weak_ptr<PixelShader> _ps;
};