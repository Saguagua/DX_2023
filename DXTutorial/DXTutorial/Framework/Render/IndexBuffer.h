#pragma once
class IndexBuffer
{
public:
	IndexBuffer(void* data, UINT count);
	~IndexBuffer();

	void SetIA_IndexBuffer();
	void SetBuffer(vector<int>* data);
	void CreateIndexBuffer(void* data);
private:
	ComPtr<ID3D11Buffer> _indexBuffer;
	D3D11_BUFFER_DESC _bd = {};
	D3D11_SUBRESOURCE_DATA _initData = {};
	UINT _count;
};

