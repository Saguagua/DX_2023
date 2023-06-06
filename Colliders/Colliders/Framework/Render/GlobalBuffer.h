#pragma once
#include "framework.h"

struct MatrixBuffer : public ConstantBuffer
{
	struct Data
	{
		XMMATRIX matrix;
	};

	MatrixBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matrix = XMMatrixIdentity();
	}

	virtual ~MatrixBuffer() {}

	void SetData(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		//DX는 열 주소 방식으로 행렬을 사용하므로 전치 필요
		_data.matrix = matrix;
	}

	Data _data;
};

struct ColorBuffer : public ConstantBuffer
{
	struct Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.color = XMFLOAT4();
	}

	virtual ~ColorBuffer() {}

	void SetColor(XMFLOAT4 color) { _data.color = color; }

	Data _data;
};