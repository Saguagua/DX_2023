#pragma once
class PaintScene : public Scene
{
public:
	PaintScene()
	{
		_circleCollider = make_shared<CircleCollider>(mousePos, 50);
		_rectangleCollider = make_shared<RectangleCollider>(mousePos, 50);
	}
	virtual ~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<CircleCollider> _circleCollider;
	shared_ptr<RectangleCollider> _rectangleCollider;
};

