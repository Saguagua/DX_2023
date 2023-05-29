#pragma once
#include "framework.h"

class MatrixBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMMATRIX matrix;
	};

	MatrixBuffer()
		:ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matrix = XMMatrixIdentity();
		//4X4 단위 행렬을 생성
	}

	virtual ~MatrixBuffer() {}

	void SetData(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		//행렬의 전치 행렬 반환
		_data.matrix = matrix;
	}

	Data _data;
};

