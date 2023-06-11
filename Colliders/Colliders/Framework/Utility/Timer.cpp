#include "framework.h"
#include "Timer.h"
Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	// �ý����� ���� ī������ ���ļ��� �����ϴ� �Լ�
	// ���� ī���ʹ� ������ �������� �����ϴ� ��
	// ���� ī������ ���ļ� ���� �� �ʴ� �ֱ⸦ ����ϴ� �� ���ȴ�.
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
	// ���� ī������ ���� ���� ��� �� ���Ǵ� �Լ�

	_timeScale = 1.0 / (double)_periodFrequency;
	// �ð� ô�� 
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	//�����쿡�� ���� ī������ ���� ��� ���� ���Ǵ� �Լ�
	//�ý����� �ϵ���� Ÿ�̸� ���� ���� ī���ͷ� ����

	_deltaTime = (double)(_curTime - _lastTime) * _timeScale;
	//�� ������ ���� ��� �ð� ����

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
