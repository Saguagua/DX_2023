#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT dataSize);
	virtual ~ConstantBuffer();

	void Update_Resource();

	void CreateBuffer();
	void SetVS_Buffer(UINT slot = 0);
	void SetPS_Buffer(UINT slot = 0);

protected:
	ComPtr<ID3D11Buffer> _buffer;

	void* _data;
	UINT _dataSize;
};

