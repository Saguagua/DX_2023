#pragma once
class Effect
{
public:
	Effect(string name, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	~Effect() {}

	void Render();
	void Update();

	void Play(Vector2 pos);
	
	void SetPos(Vector2 pos) { _transform->SetPos(pos); }
	void SetScale(Vector2 scale) { _transform->SetScale(scale); }
	void SetAngle(float angle) { _transform->SetAngle(angle); }

	bool IsActive() {return _isActive;}

private:
	void CreateAction(string name, float speed = 1.0f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void EndEvent();
	
	int _curClip = 0;
	bool _isActive = false;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Sprite>> _sprites;
	vector<shared_ptr<Action>> _actions;
};

