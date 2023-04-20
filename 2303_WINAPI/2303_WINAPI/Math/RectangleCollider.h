#pragma once
class RectangleCollider
{
public:
	RectangleCollider() {};
	RectangleCollider(Vector2 v, float radius)
		:_center(v), _radius(radius)
	{}

	void Update() {};

	void Render(HDC hdc)
	{
		float left = _center.x - _radius;
		float right = _center.x + _radius;
		float top = _center.y - _radius;
		float bottom = _center.y + _radius;

		Rectangle(hdc, left, top, right, bottom);
	}
	void SetCenter(Vector2 v) { _center = v; }
	
	Vector2 GetCenter() { return _center; }

	void SetRadius(float radius) { _radius = radius; }

	float GetRadius() { return _radius; }
	
private:
	Vector2 _center = { 0,0 };
	float _radius = 0.0f;
};

