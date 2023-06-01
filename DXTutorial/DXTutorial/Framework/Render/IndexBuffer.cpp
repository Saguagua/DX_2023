#include "framework.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(void* data, UINT count)
	:_count(count)
{
	CreateIndexBuffer(data);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::SetIA_IndexBuffer()
{
	DEVICECONTEXT->IASetIndexBuffer(_indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
}

void IndexBuffer::SetBuffer(vector<int>* data)
{
	_bd.ByteWidth = sizeof(UINT) * data->size();
	_initData.pSysMem = data;

	DEVICE->CreateBuffer(&_bd, &_initData, IN _indexBuffer.GetAddressOf());
}

void IndexBuffer::CreateIndexBuffer(void* data)
{
	_bd.Usage = D3D11_USAGE_DEFAULT;
	_bd.ByteWidth = sizeof(UINT) * _count;
	_bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

	_initData.pSysMem = data;

	DEVICE->CreateBuffer(&_bd, &_initData, IN _indexBuffer.GetAddressOf());
}
