#pragma once

#include "../../Types.h"

class Collider
{
public:
	Collider();
	~Collider();

	void SetColor(XMFLOAT4 color);
	void SetPos(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetAngle(float angle);

	void AddPos(Vector2 pos);
	void AddScale(Vector2 scale);
	void AddAngle(float angle);

	shared_ptr<Transform> GetTransform();
	void SetParent(shared_ptr<Collider> other);
	Vector2 GetWorldPos();
	Vector2 GetWorldScale();

	virtual void Update() abstract;
	virtual void Render() abstract;

	virtual bool Block(shared_ptr<Collider> other);
	virtual bool Block(shared_ptr<class CircleCollider> other) abstract;
	virtual bool Block(shared_ptr<class RectCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<Collider> other);
	virtual bool IsCollision(Vector2 other) abstract;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) abstract;

protected:
	enum class Type
	{
		NONE,
		CIRCLE,
		RECT
	};
	Type _type = Collider::Type::NONE;
	vector<Vertex> _vertices;
	XMFLOAT4 _color = GREEN;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<VertexBuffer> _vsBuffer;
	shared_ptr<VertexShader> _vsShader;
	shared_ptr<PixelShader> _psShader;
};

