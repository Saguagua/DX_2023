#pragma once
class Transform
{
public:
	Transform();
	~Transform() {}

	void Update();
	void Update_SRT();
	void Update_World();
	void Set_World(UINT slot = 0);

	void SetParent(shared_ptr<Transform> other) { _parent = other; }

	void SetScale(Vector2 scale) { _scale = scale; }
	void SetAngle(float angle) { _rotate = angle; }
	void SetPos(Vector2 pos) { _translate = pos; }

	void AddScale(Vector2 scale) { _scale += scale; }
	void AddAngle(float angle) { _rotate += angle; }
	void AddPos(Vector2 pos) { _translate += pos; }

	const Vector2& GetPos() { return _translate; }
	const Vector2& GetScale () { return _scale; }
	const float GetRotate() { return _rotate; }
	const XMMATRIX& GetSRT() { return _srt; }

	const Vector2& GetWorldPos();
	const Vector2& GetWorldScale();

private:
	shared_ptr<class MatrixBuffer> _world;
	weak_ptr<Transform> _parent;

	XMMATRIX _srt = XMMatrixIdentity();
	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _rotateM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();

	Vector2 _scale = {1.0f, 1.0f};
	float _rotate = 0.0f;
	Vector2 _translate = {0.0f, 0.0f};
};

