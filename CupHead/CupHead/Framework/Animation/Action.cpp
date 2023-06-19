#include "framework.h"
#include "Action.h"
void Action::Update()
{
	if (!_isPlay)
		return;
	_time += DELTA_TIME;

	if (_time > _speed)
	{
		_time = 0;

		switch (_repeatType)
		{
		case Action::END:
		{
			if (_playEvent != nullptr)
				_playEvent();

			_curClipIndex++;

			if (_curClipIndex >= _clips.size())
				Stop();
			break;
		}
		case Action::LOOP:
		{
			if (_playEvent != nullptr)
				_playEvent();

			_curClipIndex = (_curClipIndex + 1) % _clips.size();
			
			break;
		}
		case Action::PINGPONG:
		{
			if (_isReverse)
			{
				_curClipIndex--;
				if (_playEvent != nullptr)
					_playEvent();
				if (_curClipIndex <= 0)
					_isReverse = false;
			}
			else
			{
				_curClipIndex++;
				if (_playEvent != nullptr)
					_playEvent();
				if (_curClipIndex >= _clips.size() - 1)
					_isReverse = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

void Action::Play()
{
	_isPlay = true;
	_isReverse = false;
	_curClipIndex = 0;
	_time = 0.0f;
}

void Action::UnPause()
{
	_isPlay = true;
}

void Action::Pause()
{
	_isPlay = false;
}

void Action::Stop()
{
	_isPlay = false;
	_curClipIndex = 0;
	_time = 0.0f;

	if (_endEvent != nullptr)
		_endEvent();
	if (_endEventInt != nullptr)
		_endEventInt(5);
	if (_endEventDI != nullptr)
		_endEventDI(1, 1);
}

void Action::Reset()
{
	_isPlay = false;
	_isReverse = false;
	_curClipIndex = 0;
	_time = 0.0f;
}

void Action::SetReverse(bool set)
{
	if (set)
	{
		_isReverse = false;
		_curClipIndex = 0;
	}
	else
	{
		_isReverse = true;
		_curClipIndex = _clips.size()-1;
	}
}
