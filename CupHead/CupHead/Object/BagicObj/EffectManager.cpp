#include "framework.h"
#include "EffectManager.h"

EffectManager* EffectManager::_instance = nullptr;

void EffectManager::AddEffect(string name, Vector2 size, float angle, float speed, Action::Type type, CallBack cb)
{
	if(_effectTable.count(name) != 0)
		return;
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Effect> effect = make_shared<Effect>(name, size, speed, type);
		effect->SetAngle(angle);
		_effectTable[name].push_back(effect);
	}
}

void EffectManager::Play(string name, Vector2 pos)
{
	if (_effectTable.count(name) == 0)
		return;

	for (auto effect : _effectTable[name])
	{
		if (!effect->IsActive())
		{
			effect->Play(pos);
			return;
		}
	}
}
