#include "framework.h"
#include "Scene.h"

Scene::Scene()
{
	_test = make_shared<Quad>(L"Resource/Texture/earth.png");
}

Scene::~Scene()
{
}

void Scene::Update()
{
	_test->Update();
}

void Scene::Render()
{
	_test->Render();
}
