#pragma once
struct MatrixBuffer : public ConstantBuffer
{
	MatrixBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matrix = XMMatrixIdentity();
	}

	virtual ~MatrixBuffer() {}

	void UpdateMatrix(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		_data.matrix = matrix;
	}

private:
	struct Data
	{
		XMMATRIX matrix;
	};

	Data _data;
};

struct ColorBuffer : public ConstantBuffer
{
	ColorBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.color = XMFLOAT4();
	}

	virtual ~ColorBuffer() {}

	void SetColor(XMFLOAT4 color)
	{
		_data.color = color;
	}

private:
	struct Data
	{
		XMFLOAT4 color;
	};

	Data _data;
};

struct ActionBuffer : public ConstantBuffer
{
	ActionBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{}

	~ActionBuffer() {}

	void SetFullSize(Vector2 size)
	{
		_data.textureSize = size;
	}

	void SetStart(Vector2 pos)
	{
		_data.startPos = pos;
	}

	void SetSize(Vector2 size)
	{
		_data.size = size;
	}

private:
	struct Data
	{
		Vector2 startPos;
		Vector2 size;
		Vector2 textureSize;
		int padding[2];
	};

	Data _data;
};