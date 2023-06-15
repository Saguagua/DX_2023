#pragma once
class Action
{
public:
	struct Clip
	{

		Clip(float x, float y, float w, float h, shared_ptr<SRV> srv)
			:startPos(x, y), size(w,h), srv(srv)
		{
		}

		Vector2 startPos;
		Vector2 size;
		weak_ptr<SRV> srv;
	};

	enum Type
	{
		END,
		LOOP,
		PINGPONG
	};

	Action(vector<vector<Clip>> clips, string name = "", Type type = Type::LOOP, float speed = 0.1f);
	~Action() {}

	void Update();

	void Play();
	void Pause();
	void Stop();
	void Reset();
	void SetCurClip(int y) {_curClipIndexY = y; }
	Clip GetCurClip() { return _clips[_curClipIndexY][_curClipIndexX]; }

	void SetEndEvent(CallBack event_) { _endEvent = event_; }
	void SetType(Action::Type type) { _repeatType = type; }

private:
	string _name;
	vector<vector<Clip>> _clips;

	Type _repeatType;
	bool _isPlay = false;

	UINT _curClipIndexX = 0;
	UINT _curClipIndexY = 0;

	float _time = 0.0f;
	float _speed = 0.0f;

	bool _isReverse = false;

	CallBack _endEvent = nullptr;
};

