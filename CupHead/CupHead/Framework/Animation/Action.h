#pragma once
#include "Types.h"
class Action
{
public:
	struct Clip
	{
		Vector2 startPos;
		Vector2 size;
		weak_ptr<SRV> srv;

		Clip(float x, float y, float w, float h, shared_ptr<SRV> srv)
			: startPos(x, y), size(w, h), srv(srv)
		{}
	};
	enum Type
	{
		END,
		LOOP,
		PINGPONG
	};

	Action(vector<Clip> clips, string name = "", Type type = Type::LOOP, float speed = 1.0f)
	: _clips(clips), _name(name), _repeatType(type), _speed(speed){}
	~Action() {}

	void Update();
	void Play();
	void UnPause();
	void Pause();
	void Stop();
	void Reset();

	Clip GetCurClip() { return _clips[_curClipIndex]; }

	void SetStartEvent(CallBack callback) { _startEvent = callback; }
	void SetStartEventBool(CallBackBool callback) { _startEventBool = callback; }

	void SetPlayEvent(CallBack callback) { _playEvent = callback; }
	void SetPlayEventBool(CallBackBool callback) { _playEventBool = callback; }

	void SetEndEvent(CallBack callback) { _endEvent = callback; }
	void SetEndEventInt(CallBackInt callback) { _endEventInt = callback; }
	void SetEndEventDI(CallBackDI callback) { _endEventDI = callback; }
	void SetEndEventBool(CallBackBool callback) { _endEventBool = callback; }
	
	void SetReverse(bool set);

	bool IsPlaying() { return _isPlay; }

private:
	string _name;
	vector<Clip> _clips;

	Type _repeatType;
	bool _isPlay = false;

	UINT _curClipIndex = 0;

	float _time = 0.0f;
	float _speed = 0.0f;

	bool _isReverse = false;

	CallBack _startEvent = nullptr;
	CallBackBool _startEventBool = nullptr;

	CallBack _playEvent = nullptr;
	CallBackBool _playEventBool = nullptr;

	CallBack _endEvent = nullptr;
	CallBackInt _endEventInt = nullptr;
	CallBackDI _endEventDI = nullptr;
	CallBackBool _endEventBool = nullptr;
};

