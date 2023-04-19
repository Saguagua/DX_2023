#pragma once
class PaintScene : public Scene
{
public:
	PaintScene()
	{
		_circleCollider = CircleCollider();
	}
	virtual ~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	CircleCollider _circleCollider;

};

