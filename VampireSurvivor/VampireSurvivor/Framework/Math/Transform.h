#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Update_SRT();
	void Update_World();
	void Set_World(UINT slot = 0);

	void SetParent(shared_ptr<Transform> other) { _parent = other; }

	void AddScale(Vector2 scale) { _scale += scale; }
	void AddAngle(float angle) { _angle += angle; }
	void AddPos(Vector2 pos) { _pos += pos; }

	void SetScale(Vector2 scale) { _scale = scale; }
	void SetAngle(float angle) { _angle = angle; }
	void SetPos(Vector2 pos) { _pos = pos; }

	XMMATRIX GetSRT() { return _srt; }
	Vector2 GetWorldPos();
	Vector2 GetWorldScale();
private:
	shared_ptr<class MatrixBuffer> _world;

	Vector2 _scale = {1.0f, 1.0f};
	float _angle = 0.0f;
	Vector2 _pos = {0.0f, 0.0f};

	XMMATRIX _srt = XMMatrixIdentity();
	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _rotateM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();

	weak_ptr<Transform> _parent;
};

