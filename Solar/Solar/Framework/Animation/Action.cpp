#include "framework.h"
#include "Action.h"

Action::Action(vector<vector<Clip>> clips, string name, Type type, float speed)
	:_clips(clips)
	, _name(name)
	, _repeatType(type)
	, _speed(speed)
{
}

void Action::Update()
{
	if (_isPlay == false)
		return;

	_time += DELTA_TIME;
	int size = _clips[_curClipIndexY].size();

	if (_time > _speed * 10 / size)
	{
		_time = 0.0f;

		switch (_repeatType)
		{
		case Action::END:
		{
			_curClipIndexX++;
			if (_curClipIndexX >= size)
				Stop();
		}
		break;
		case Action::LOOP:
		{
			_curClipIndexX++;
			_curClipIndexX %= size;
		}
		break;
		case Action::PINGPONG:
		{
			if (_isReverse)
			{
				_curClipIndexX--;
				if (_curClipIndexX <= 0)
					_isReverse = false;
			}
			else
			{
				_curClipIndexX++;
				if (_curClipIndexX >= size - 1)
					_isReverse = true;
			}
		}
		break;
		default:
			break;
		}
	}
}

void Action::Play()
{
	_isPlay = true;
	_isReverse = false;
	_time = 0.0f;
}

void Action::Pause()
{
	_isPlay = false;
}

void Action::Stop()
{
	_isPlay = false;
	_time = 0.0f;
	_curClipIndexX = 0;

	if (_endEvent != nullptr)
		_endEvent();
}

void Action::Reset()
{
	_isPlay = false;
	_curClipIndexX = 0;
	_time = 0.0f;
}
