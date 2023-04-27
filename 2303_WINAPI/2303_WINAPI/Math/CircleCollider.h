#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>, public Collider
{
public:
	CircleCollider() :Collider(Vector2(0, 0)) 
	{ _type = Collider::Type::CIRCLE; }

	CircleCollider(float radius, Vector2 center) : _radius(radius), Collider(center) 
	{ _type = Collider::Type::CIRCLE; }

	virtual ~CircleCollider() {};

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetRadius(float radius) { _radius = radius; }
	float GetRadius() { return _radius; }

	bool IsCollision(Vector2 other);
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectangleCollider> other) override;

private:
	float _radius = 50.0f;

};

