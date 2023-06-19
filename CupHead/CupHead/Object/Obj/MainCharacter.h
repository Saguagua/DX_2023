#pragma once
class MainCharacter
{
public:
	enum Player_State
	{
		IDLE_PLAYER = (1 << 0),
		RUN_PLAYER = (1 << 1),
		ONAIR_PLAYER = (1 << 2),
		DOWN_PLAYER = (1 << 3),
		ATTACK_PLAYER = (1 << 4),
		LOCK_PLAYER = (1 << 5),
		DAMAGED_PLAYER = (1 << 6),
		DEAD_PLAYER = (1 << 7)
	};

	enum Action_State
	{
		IDLE_ACTION,
		RUN_ACTION,
		JUMP_ACTION,
		DOWN_ACTION,
		DOWNIDLE_ACTION,
		ATTACK_FRONT_ACTION,
		ATTACK_UP_ACTION,
		ATTACK_DOWN_ACTION,
		ATTACK_DIAGONAL_UP_ACTION,
		ATTACK_DIAGONAL_DOWN_ACTION,
		ATTACK_RUN_ACTION,
		ATTACK_DUCK_ACTION,
		AIM_FRONT_ACTION,
		AIM_UP_ACTION,
		AIM_DOWN_ACTION,
		AIM_DIAGONAL_UP_ACTION,
		AIM_DIAGONAL_DOWN_ACTION,
		HIT_ACTION

	};

	MainCharacter();
	~MainCharacter() {}

	void Update();
	void Render();
	void PostRender();

	void SetOnGround();
	void SetOnAir();

	shared_ptr<CircleCollider> GetCollider() { return _col; }
	shared_ptr<Transform> GetTransform() { return _transform; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

	void GetDamage(int amount);

private:
	void CreateAction(string name, float speed = 1.0f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void SetAction(Action_State state, bool reverse = false);
	void Input();
	void SetIdle();
	void SetAim();
	void Fire(Vector2 pos, Vector2 dir, Action_State state, int front);
	void FireEnd();

	void SetLeft()
	{
		for (auto sprite : _sprites)
			sprite->SetLeft();
	}
	void SetRight()
	{
		for (auto sprite : _sprites)
			sprite->SetRight();
	}

	vector<shared_ptr<class Bullet>> _bullets;

	shared_ptr<CircleCollider> _col;
	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _bulletSlot;
	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite>> _sprites;

	Action_State _state = Action_State::IDLE_ACTION;
	
	unsigned int _bitFlag = 0;
	
	Vector2 _dir = {1,0};

	bool _spaceDown;
	double _jumpDuration;

	float _moveSpeed = 300.0f;
	float _jumpSpeed = 500.0f;

	int _hp = 4;
};

