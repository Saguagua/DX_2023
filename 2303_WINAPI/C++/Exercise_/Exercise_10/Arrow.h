#pragma once
#include <memory>

class Player;

class Arrow
{
public:
	Arrow(std::shared_ptr<Player> target, int damage);
	~Arrow();

public:
	void AttackTarget();

public:
	std::weak_ptr<Player> _target;
	int _damage;
};

