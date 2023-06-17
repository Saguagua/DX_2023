#pragma once
class CircleCollider :public Collider, enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider(float radius);
	virtual ~CircleCollider() {}

	bool Block(shared_ptr<CircleCollider> col);
	bool Block(shared_ptr<RectCollider> col) { return false; }

	float GetRadius() { return _radius; }
	float GetWorldRadius();
	
	virtual void Update() override;
	virtual void Render() override;

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> col) override;
	virtual bool IsCollision(shared_ptr<RectCollider> col) override;

private:
	virtual void CreateData() override;
	virtual void CreateVertices() override;
	
	float _radius;
};

