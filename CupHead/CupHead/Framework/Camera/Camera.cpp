#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_view = make_shared<Transform>();
	_projection = make_shared<MatrixBuffer>();

	XMMATRIX projMatrix = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);
}

void Camera::Update()
{
}

void Camera::PostRender()
{
}

void Camera::ShakeStart(float magnitude, float duration, float reduceDumping)
{
}

void Camera::SetViewPort(UINT width, UINT height)
{
}

void Camera::SetViewBuffer()
{
	_view->Set_World(1);
}

void Camera::SetProjectionBuffer()
{
	_projection->SetVS_Buffer(2);
}

void Camera::Shake()
{
}

void Camera::FreeMode()
{
}

void Camera::FollowMode()
{
}
