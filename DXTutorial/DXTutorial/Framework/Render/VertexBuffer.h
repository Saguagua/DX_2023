#pragma once
class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~VertexBuffer();

	void SetIA_VertexBuffer(UINT slot = 0);
	void SetBuffer(vector<Vertex>* other);
private:
	void CreateVertexBuffer();

	ComPtr<ID3D11Buffer> _vertexBuffer;
	D3D11_BUFFER_DESC _bd = {};
	D3D11_SUBRESOURCE_DATA _initData = {};

	void* _data = nullptr;
	UINT _stride = 0;
	UINT _count = 0;
	UINT _offset = 0;
};

