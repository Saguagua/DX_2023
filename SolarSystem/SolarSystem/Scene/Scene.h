#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _test;
	shared_ptr<Planet> _sun;
	shared_ptr<Planet> _earth;
	shared_ptr<Planet> _moon;
};

