#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>, public Collider
{
public:
	CircleCollider(float radius);
	virtual ~CircleCollider();

	float GetRadius() { return _radius; }
	float GetWorldRadius();

	virtual void Update() override;
	virtual void Render() override;
	virtual bool IsCollision(Vector2 other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other) override;
private:
	void CreateVertices();
	void CreateData();

	float _radius;

	// Collider을(를) 통해 상속됨
};