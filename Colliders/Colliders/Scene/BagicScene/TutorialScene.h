#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _rect2;
	shared_ptr<Collider> _rect3;
	shared_ptr<Collider> _circle;
	shared_ptr<Collider> _circle2;
	shared_ptr<Collider> _circle3;
};

