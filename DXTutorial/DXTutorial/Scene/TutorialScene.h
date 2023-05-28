#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Line> _line;

	float _x = 0.0f;
	float _y = 0.0f;
};

