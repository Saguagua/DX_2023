#pragma once
struct MatrixBuffer :public ConstantBuffer
{
	MatrixBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matirx = XMMatrixIdentity();
	}

	virtual ~MatrixBuffer() {}

	void SetMatrix(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		_data.matirx = matrix;
	}

private:
	struct Data
	{
		XMMATRIX matirx;
	};

	Data _data;
};

struct ColorBuffer :public ConstantBuffer
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

	virtual ~ActionBuffer() {}

	void SetStart(Vector2 start)
	{
		_data.startPos = start;
	}

	void SetClipSize(Vector2 clipSize)
	{
		_data.clipSize = clipSize;
	}

	void SetfullSize(Vector2 full)
	{
		_data.fullSize = full;
	}

private:
	struct Data
	{
		Vector2 startPos = {0.0f, 0.0f};
		Vector2 fullSize = {0.0f, 0.0f};
		Vector2 clipSize = {0.0f, 0.0f};
		int padding[2];
	};

	Data _data;
};