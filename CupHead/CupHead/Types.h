#pragma once
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER			Vector2(WIN_WIDTH/2, WIN_HEIGHT/2)
#define UP_VECTOR		 Vector2(0.0f, 1.0f)
#define RIGHT_VECTOR	 Vector2(1.0f, 0.0f)

#define MOUSE_POS		InputManager::GetInstance()->GetMousePos()

#define FPS				Timer::GetInstance()->GetFPS()
#define DELTA_TIME		Timer::GetInstance()->GetDeltaTime()
#define RUN_TIME		Timer::GetInstance()->GetRunTime()

#define PI 3.141592

#define RED			{1.0f,0.0f,0.0f,1.0f}
#define GREEN		{0.0f,1.0f,0.0f,1.0f}
#define BLUE		{0.0f,0.0f,1.0f,1.0f}

#define DEVICE Device::GetInstance()->GetDevice()
#define DC Device::GetInstance()->GetDC()

#define ADD_VS(k) ShaderManager::GetInstance()->Add_Vs(k)
#define ADD_PS(k) ShaderManager::GetInstance()->Add_Ps(k)