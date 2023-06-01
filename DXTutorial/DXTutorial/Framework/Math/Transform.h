#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void SetBuffer(UINT slot = 0);
	void UpdateBuffer();
	void UpdateSRT();

	void AddPos(Vector2<float> pos);
	void AddScale(Vector2<float> scale);
	void AddAngle(float angle);


private:
	Vector2<float> _pos = {0.0f, 0.0f};
	Vector2<float> _scale = {1.0f, 1.0f};
	float _angle = 0.0f;

	shared_ptr<class MatrixBuffer> _world;
	XMMATRIX _srt;
};

