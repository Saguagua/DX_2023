#pragma once
class SpriteFrame :public Sprite
{
public:
	SpriteFrame(wstring path, Vector2 maxFrame);
	virtual ~SpriteFrame() {}

	void SetCurFrame(Vector2 curClip);
private:
	Vector2 _maxFrame;
};

