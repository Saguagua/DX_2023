#pragma once
class CircleCollider;
class RectangleCollider;

class Collider
{
public:
	enum class Type
	{
		NORMAL,
		CIRCLE,
		RECANGLE,
		LINE
	};

	Collider(Vector2 center)
		: _center(center)
	{
		CreatePens();
	}

	virtual ~Collider()
	{
		for (HPEN pen : _pens)
			DeleteObject(pen);
	}

	void SetCenter(Vector2 pos) { _center = pos; }
	Vector2& GetCenter() { return _center; }
	
	void SetGreen() { _penIndex = 0; }
	void SetRed() { _penIndex = 1; }

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	
	bool IsCollision(shared_ptr<Collider> other);
	virtual bool IsCollision(shared_ptr<CircleCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<RectangleCollider> other) abstract;
	
protected:
	void CreatePens();

	int _penIndex = 0;
	vector<HPEN> _pens;

	Type _type = Collider::Type::NORMAL;
	
	Vector2 _center = {0,0};

};

