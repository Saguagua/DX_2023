#pragma once
class Sprite : public Quad
{
protected:
	Sprite(wstring path);
	Sprite(wstring path, Vector2 size);
	virtual ~Sprite() {}

public:
	virtual void Update();
	virtual void Render();

protected:
	virtual void CreateVertex() override;
	virtual void CreateData() override;

	shared_ptr<ActionBuffer> _actionBuffer;
};

