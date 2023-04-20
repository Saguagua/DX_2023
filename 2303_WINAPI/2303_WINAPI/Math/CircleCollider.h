#pragma once
class CircleCollider
{
public:
	CircleCollider() {};
	CircleCollider(Vector2 v, float radius)
		:_center(v), _radius(radius)
	{}
	~CircleCollider() {};
	void Update();
	void Render(HDC hdc);

	Vector2 GetCenter() { return _center; }
	void SetCenter(Vector2 v);

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }
private:
	Vector2 _center = {0,0};
	float _radius = 0.0f;
};

