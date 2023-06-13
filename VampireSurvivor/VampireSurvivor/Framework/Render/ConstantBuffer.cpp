#include "framework.h"
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(void* data, UINT size)
	:_data(data), _size(size)
{
	CreateBuffer();
}

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::UpdateData()
{
    DC->UpdateSubresource(_constantBuffer.Get(), 0, nullptr, _data, 0, 0);
}

void ConstantBuffer::SetVS_Buffer(UINT slot)
{
    DC->VSSetConstantBuffers(slot, 1, _constantBuffer.GetAddressOf());
}

void ConstantBuffer::SetPS_Buffer(UINT slot)
{
    DC->PSSetConstantBuffers(slot, 1, _constantBuffer.GetAddressOf());
}

void ConstantBuffer::CreateBuffer()
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = _size;
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _data;

    DEVICE->CreateBuffer(&bd, &initData, IN _constantBuffer.GetAddressOf());
}

