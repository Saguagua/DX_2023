#include "framework.h"
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(void* data, UINT dataSize)
	:_data(data), _dataSize(dataSize)
	//void*�� ��� �ڷ����� ���� �� �ִ�
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
	//������ �����͸� ������Ʈ�ϴ� �Լ�
}

void ConstantBuffer::SetVS_Buffer(UINT slot)
{
	DEVICECONTEXT->VSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
	//�������Ϳ� ���� ���
}

void ConstantBuffer::SetPS_Buffer(UINT slot)
{
	DEVICECONTEXT->PSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
}
