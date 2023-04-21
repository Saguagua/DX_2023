#pragma once
class RectangleCollider :public Collider
{
public:
	RectangleCollider()
		:Collider(Vector2(0,0))
	{_type = Collider::Type::RECANGLE;}

	RectangleCollider(Vector2 center, Vector2 size) 
		:Collider(center), _size(size)
	{_type = Collider::Type::RECANGLE;}

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	float Left() const { return _center.x - _size.x * 0.5f; }
	float Right() const { return _center.x + _size.x * 0.5f; }
	float Bottom() const { return _center.y + _size.y * 0.5f; }
	float Top() const { return _center.y - _size.y * 0.5f; }

	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectangleCollider> other) override;
private:
	Vector2 _size = { 0,0 };
};

