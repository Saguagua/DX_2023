#include "framework.h"
#include "Timer.h"
Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	// 시스템의 성능 카운터의 주파수를 측정하는 함수
	// 성능 카운터는 고정된 간격으로 증가하는 값
	// 성능 카운터의 주파수 값을 얻어서 초당 주기를 계산하는 데 사용된다.
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
	// 성능 카운터의 현재 값을 얻는 데 사용되는 함수

	_timeScale = 1.0 / (double)_periodFrequency;
	// 시간 척도 
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	//윈도우에서 고성능 카운터의 값을 얻기 위해 사용되는 함수
	//시스템의 하드웨어 타이머 또한 고성능 카운터로 구성

	_deltaTime = (double)(_curTime - _lastTime) * _timeScale;
	//각 프레임 간의 경과 시간 측정

	if (_lockFPS != 0)
	{
		while (_deltaTime < (1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_deltaTime = (double)(_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _deltaTime;

	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		// FPS : frame per second
		_oneSecCount = 0;
		_frameCount = 0;
	}

	_runTime += _deltaTime;
}
