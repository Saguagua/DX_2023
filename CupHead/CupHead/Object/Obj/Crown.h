#pragma once
class Crown
{
public:
	enum Action_State
	{
		INTRO_IDLE,
		INTRO_1,
		INTRO_2,
		MOVE_1,
		MOVE_BREAK_1,
		MOVE_2,
		MOVE_BREAK_2,
		MOVE_3,
		BODY_INTRO_IDLE,
		BODY_INTRO_1,
		BODY_IDLE,
		DISABLE,
		HEAD_INTRO_IDLE,
		HEAD_INTRO_1,
		INTRO_HEAD
	};

	Crown();
	~Crown() {}

	void Update();
	void Render();

	vector<shared_ptr<Bullet>>& GetBullets() { return _bullets; }
	shared_ptr<CircleCollider> GetCollider() { return _main_col; }
private:
	void NextStage(); 
	void CreateAction(string name, float scale = 1, float speed = 1.0f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void SetAction(Action_State state);
	void SetAction(int state);
	void NextIndex(int num) { SetAction(num); }
	void MoveDelay(double timer, int index);
	void Move();

	shared_ptr<Transform> _main_trans;
	shared_ptr<Transform> _second_trans;
	shared_ptr<CircleCollider> _main_col;
	shared_ptr<CircleCollider> _second_col;
	vector<shared_ptr<Sprite>> _sprites;
	vector<shared_ptr<Action>> _actions;

	vector<shared_ptr<class Bullet>> _bullets;

	Action_State _mainState = Action_State::INTRO_IDLE;
	Action_State _secondState = Action_State::HEAD_INTRO_IDLE;

	bool _isLeft = true;

	int _mainIndex = 0;
	int _nextIndex = 0;

	int _hp = 100;
	int _stage = 0;
	double _stopTimer = -10;
};

