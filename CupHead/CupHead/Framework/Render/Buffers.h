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

	void SetFullSize(Vector2 full)
	{
		_data.fullSize = full;
	}

	Vector2 GetClipSize() { return _data.clipSize; }
	Vector2 GetFullSize() { return _data.fullSize; }
	Vector2 GetStartPos() { return _data.startPos; }
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

struct IntBuffer :public ConstantBuffer
{
	IntBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{}

	virtual ~IntBuffer() {}

	void SetSlot1(int val) { _data.val1 = val; }
	void SetSlot2(int val) { _data.val2 = val; }
	void SetSlot3(int val) { _data.val3 = val; }
	void SetSlot4(int val) { _data.val4 = val; }

	int GetSlot1() { return _data.val1; }
	int GetSlot2() { return _data.val2; }
	int GetSlot3() { return _data.val3; }
	int GetSlot4() { return _data.val4; }
private:
	struct Data
	{
		int val1 = 0;
		int val2 = 0;
		int val3 = 0;
		int val4 = 0;
	};

	Data _data;
};

struct FilterBuffer :public ConstantBuffer
{
	FilterBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{}

	virtual ~FilterBuffer() {}

	void SetType(int val) { _data.type = val; }
	void SetVal1(int val) { _data.val1 = val; }
	void SetVal2(int val) { _data.val2 = val; }
	void SetVal3(int val) { _data.val3 = val; }
	void SetImageSize(Vector2 v) { _data.imageSize = v; }
	void SetRadialCenter(Vector2 v) { _data.radialCenter = v; }

	int GetType() { return _data.type; }
	int GetVal1() { return _data.val1; }
	int GetVal2() { return _data.val2; }
	int GetVal3() { return _data.val3; }
	Vector2 GetSize() { return _data.imageSize; }
	Vector2 GetRadial() { return _data.radialCenter; }

	struct Data
	{
		int type = 0;
		int val1 = 0;
		int val2 = 0;
		int val3 = 0;

		Vector2 imageSize;
		Vector2 radialCenter;
	};

	Data _data;
 private:
	

	
};