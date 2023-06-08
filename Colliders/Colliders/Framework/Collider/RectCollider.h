#pragma once
class RectCollider:public Collider
{
public:
	struct AABB_Info
	{
		float left = 0;
		float right = 0;
		float top = 0;
		float bottom = 0;
	};

	struct OBB_Info
	{
		Vector2 pos;
		Vector2 direction[2];
		float length[2];
	};

	RectCollider(Vector2 size);
	~RectCollider();

	AABB_Info GetAABB_Info();
	OBB_Info GetOBB_Info();

	float SeperateAxis(Vector2 seperate, Vector2 eb1, Vector2 eb2);

	// Collider을(를) 통해 상속됨
	virtual void SetScale(Vector2 scale) override;

	virtual void Update() override;
	virtual void Render() override;

	bool IsOBB(shared_ptr<RectCollider> other);
	virtual bool IsCollision(Vector2 other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) override;

private:
	void CreateVertices();
	void CreateData();

	Vector2 _size;
};

