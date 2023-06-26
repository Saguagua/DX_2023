#pragma once
class Camera
{
private:
	Camera();
	~Camera() {}

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Camera* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void PostRender();
	void ShakeStart(float magnitude, float duration, float reduceDumping = 1.0f);

	void SetViewPort(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetViewBuffer();
	void SetProjectionBuffer();
	void SetTarget(shared_ptr<Transform> target) {_target = target;}
	void SetLeftBottom(Vector2 v) {_leftBottom = v;}
	void SetRightTop(Vector2 value) {_rightTop = value;}
	void SetOffset(Vector2 value) {_offset = value;}


private:
	void Shake();
	void FreeMode();
	void FollowMode();

	static Camera* _instance;

	shared_ptr<Transform> _view;
	shared_ptr<MatrixBuffer> _projection;

	
	float _speed = 100.0f;

	weak_ptr<Transform> _target;
	Vector2 _offset;

	Vector2 _leftBottom;
	Vector2 _rightTop;

	float _duration = 0.0f;
	float _magnitude = 0.0f;
	float _reduceDamping = 0.0f;

	Vector2 _originPos;
	Vector2 _winSize;
};

