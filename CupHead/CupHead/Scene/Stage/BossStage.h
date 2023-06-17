#pragma once
class BossStage :public Scene
{
public:
	BossStage();
	~BossStage();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<CircleCollider> _cir;
	shared_ptr<RectCollider> _rec;
};

