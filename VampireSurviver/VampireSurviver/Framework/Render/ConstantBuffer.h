#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT size);
	~ConstantBuffer();

	void UpdateData();

	void SetPS_Buffer(UINT slot = 0);
	void SetVS_Buffer(UINT slot = 0);

private:
	void CreateBuffer();

	ComPtr<ID3D11Buffer> _constantBuffer;

	void* _data;
	UINT _size;
};