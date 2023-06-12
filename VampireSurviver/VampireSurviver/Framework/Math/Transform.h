#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Update_SRT();
	void Update_World();
	void SetWorld(UINT slot);
	void SetParent(shared_ptr<Transform> other) { _parent = other; }

	Vector2 GetScale() { return _scale; }
	float GetAngle() { return _angle; }
	Vector2 GetPos() { return _pos; }

	void SetScale(Vector2 scale) { _scale = scale; }
	void SetRotate(float angle) { _angle = angle; }
	void SetPos(Vector2 pos) { _pos = pos; }

	void AddScale(Vector2 scale) { _scale += scale; }
	void AddAngle(float angle) { _angle += angle; }
	void AddPos(Vector2 pos) { _pos += pos; }

	Vector2 GetWorldPos();
	Vector2 GetWorldScale();

	XMMATRIX GetSRT();
private:
	XMMATRIX _srt = XMMatrixIdentity();
	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();
	XMMATRIX _rotateM = XMMatrixIdentity();

	Vector2 _scale = { 1.0f, 1.0f };
	FLOAT _angle = 0.0f;
	Vector2 _pos;

	shared_ptr<class MatrixBuffer> _world;
	weak_ptr<Transform> _parent;
};

