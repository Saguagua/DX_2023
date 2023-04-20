#pragma once
class RectangleCollider
{
public:
	RectangleCollider();
	RectangleCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	float Left() const { return _center.x - _size.x * 0.5f; }
	float Right() const { return _center.x + _size.x * 0.5f; }
	float Bottom() const { return _center.y + _size.y * 0.5f; }
	float Top() const { return _center.y - _size.y * 0.5f; }

	bool IsCollision(const Vector2& pos);
	bool IsCollision(shared_ptr<RectangleCollider> other);
	bool IsCollision(shared_ptr<class CircleCollider> other);

	void SetCenter(const Vector2& center);
	Vector2 GetCenter() { return _center; }

	void SetGreen() { _curPenIdex = 0; }
	void SetRed() { _curPenIdex = 1; }

private:
	void CreatePens();

	int _curPenIdex;
	vector<HPEN> _pens;

	Vector2 _center = { 0,0 };
	Vector2 _size = { 0,0 };
};

