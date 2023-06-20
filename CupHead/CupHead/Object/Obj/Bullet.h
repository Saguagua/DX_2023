#pragma once
class Bullet
{
public:
	enum State
	{
		INTRO,
		LOOP,
		END
	};
	Bullet(string path, float size);
	~Bullet() {}

	void Update();
	void Render();

	void SetActive(bool val) { _isActive = val; }
	bool IsActive() { return _isActive; }
	void Shoot(Vector2 dir, Vector2 pos);
	shared_ptr<CircleCollider> GetCollider() { return _col; }

	void SetSpeed(float speed) { _speed = speed; }

private:
	void CreateAction(string name, float speed = 1.0f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void ToLoop();
	void ToEnd();
	void ToFinish();

	State _state = State::INTRO;
	
	Vector2 _dir = { 1,0 };

	float _speed = 600.0f;
	float _angle = 0.0f;

	double _curTime = 0.0;
	double _lifeTime = 5.0;

	bool _isActive = false;

	shared_ptr<Transform> _transform;
	shared_ptr<CircleCollider> _col;
	vector<shared_ptr<Sprite>> _sprites;
	vector<shared_ptr<Action>> _actions;
};

