#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

private:
	Vector2 _pos = CENTER;
	Vector2 _scale = {1.0f, 1.0f};
	float _angle = 0.0f;

	shared_ptr<RectCollider> _rect;
	shared_ptr<RectCollider> _rect2;
	shared_ptr<RectCollider> _rect3;
	shared_ptr<Collider> _circle;
	shared_ptr<Collider> _circle2;
	shared_ptr<Collider> _circle3;
};

