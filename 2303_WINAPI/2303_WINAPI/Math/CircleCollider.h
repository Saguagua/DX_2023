#pragma once
class CircleCollider
{
public:
	CircleCollider() {};
	CircleCollider(Vector2 vector):_center(vector), _radius(100){};
	CircleCollider(float radius, Vector2 center){};
	~CircleCollider() {};
	void Update();
	void Render(HDC);

private:
	Vector2 _center;
	float _radius;
};

