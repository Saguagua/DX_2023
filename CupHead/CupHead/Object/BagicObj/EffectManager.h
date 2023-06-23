#pragma once
#include "Object/BagicObj/Effect.h"
#include "Framework/Animation/Action.h"

class EffectManager
{
private:
	EffectManager(){};
	~EffectManager(){}

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new EffectManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static EffectManager* GetInstance() 
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update()
	{
		for (auto pair : _effectTable)
		{
			for (auto effect : pair.second)
				effect->Update();
		}
	}

	void Render()
	{
		for (auto pair : _effectTable)
		{
			for (auto effect : pair.second)
				effect->Render();
		}
	}

	void AddEffect(string name, Vector2 size, float angle = 0, float speed = 0.1f, Action::Type type = Action::Type::END, CallBack cb = nullptr);

	void Play(string name, Vector2 pos);
private:
	static EffectManager* _instance;
	unordered_map<string, vector<shared_ptr<Effect>>> _effectTable;
	unsigned int _poolCount = 30; 
};

