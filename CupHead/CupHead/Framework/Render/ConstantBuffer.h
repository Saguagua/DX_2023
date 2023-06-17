#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT size);
	~ConstantBuffer() {}

	void Update_Resource();

	void SetVS_Buffer(UINT slot);
	void SetPS_Buffer(UINT slot);

private:
	void CreateBuffer();
	ComPtr<ID3D11Buffer> _cBuffer;
	void* _data;
	UINT _size;
};