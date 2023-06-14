#pragma once
class Sprite: public Quad
{
public:
	Sprite(wstring path, Vector2 maxFrame);
	Sprite(wstring path, Vector2 maxFrame, Vector2 size);
	virtual ~Sprite() {}

	virtual void Update() override;
	virtual void Render() override;

	void SetCurClip(Vector2 frame);
	void SetCurClip(Action::Clip clip);

private:
	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

	shared_ptr<ActionBuffer> _actionBuffer;
	Vector2 _maxFrame;
};

