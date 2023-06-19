#pragma once
class BackGround
{
public:
	BackGround();
	~BackGround() {}

	void Update();
	void Render();

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _transform;
};

