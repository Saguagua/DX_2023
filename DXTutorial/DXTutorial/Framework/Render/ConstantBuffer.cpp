#include "framework.h"
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(void* data, UINT dataSize)
	:_data(data), _dataSize(dataSize)
	//void*는 모든 자료형을 담을 수 있다
{
	CreateBuffer();
}

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::CreateBuffer()
{
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = _dataSize;
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = _data;

	DEVICE->CreateBuffer(&bd, &initData, IN _buffer.GetAddressOf());
}

void ConstantBuffer::Update_Resource()
{
	DEVICECONTEXT->UpdateSubresource(_buffer.Get(), 0, nullptr, _data, 0, 0);
	//버퍼의 데이터를 업데이트하는 함수
}

void ConstantBuffer::SetVS_Buffer(UINT slot)
{
	DEVICECONTEXT->VSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
	//레지스터에 버퍼 등록
}

void ConstantBuffer::SetPS_Buffer(UINT slot)
{
	DEVICECONTEXT->PSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
}
