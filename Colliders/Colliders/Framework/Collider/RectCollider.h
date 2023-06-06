#pragma once
class RectCollider:public Collider
{
public:
	RectCollider(Vector2 size);
	~RectCollider();

	// Collider을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	virtual bool IsCollision(Vector2 other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) override;

private:
	struct AABB_Info
	{
		float left = 0;
		float right = 0;
		float top = 0;
		float bottom = 0;
	};

	void CreateVertices();
	void CreateData();

	Vector2 _size;
};

