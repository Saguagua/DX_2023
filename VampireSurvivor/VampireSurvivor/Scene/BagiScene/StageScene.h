#pragma once
class StageScene: public Scene
{
public:
	StageScene();
	virtual ~StageScene() {}

	virtual void Update() override;
	virtual void Render() override;

private:

};

