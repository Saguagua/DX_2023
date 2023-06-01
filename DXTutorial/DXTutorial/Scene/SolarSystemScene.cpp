#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_earth = make_shared<Planet>(EARTH);
	_moon = make_shared<Planet>(MOON);
	_sun = make_shared<Planet>(SUN);

	_sun->SetPosition(CENTER);
	_earth->SetPosition(Vector2<float>(300.0f, 300.0f));
	_moon->SetPosition(Vector2<float>(200.0f, 100.0f));
}

SolarSystemScene::~SolarSystemScene()
{}

void SolarSystemScene::Update()
{
	_moon->Update();
	_earth->Update();
	_sun->Update();
}

void SolarSystemScene::Render()
{
	_moon->Render();
	_earth->Render();
	_sun->Render();
}