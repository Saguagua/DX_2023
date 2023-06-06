#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _circle;
};

