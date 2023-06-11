#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Update_SRT();
	void Update_World();
	void Set_World(UINT slot);
	void SetParent(shared_ptr<Transform> other);

	Vector2 GetScale();
	float GetAngle();
	Vector2 GetPos();

	void SetScale(Vector2 scale);
	void SetRotate(float angel);
	void SetPos(Vector2 pos);

	void AddScale(Vector2 scale);
	void AddAngle(float angle);
	void AddPos(Vector2 pos);

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

