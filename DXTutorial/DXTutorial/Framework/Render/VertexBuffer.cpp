#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count, UINT offset)
: _stride(stride)
, _count(count)
, _offset(offset)
, _data(data)
{
	CreateVertexBuffer();
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::SetIA_VertexBuffer(UINT slot)
{

    DEVICECONTEXT->IASetVertexBuffers(slot, 1, _vertexBuffer.GetAddressOf(), &_stride, &_offset);
    //�Է� ������� ��� �� ���ؽ� ���۸� �����ϴ� �Լ�
    //�Ű�����
    //1. ������ ������ ����
    //2. ������ ������ ����
    //3. ������ �������̽� ������ �迭�� ��Ÿ���� ���� ������
    //4. �� ������ ���ؽ� ũ��
    //5. �� ������ ������
    
}

void VertexBuffer::CreateVertexBuffer()
{
    D3D11_BUFFER_DESC bd = {};
    //���� ��ü�� �����ϱ� ���� ����ü
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = _stride * _count;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    //���۳� �ؽ�ó�� ���� ���ҽ� �����͸� �ʱ�ȭ�ϱ� ���� ����ü
    initData.pSysMem = _data;
    //�ʱ�ȭ�� �����Ͱ� �ִ� ������

    DEVICE->CreateBuffer(&bd, &initData, IN _vertexBuffer.GetAddressOf());
    //���� �����Լ�
    //bd�� ũ��, ����, ���ε� �÷��� ���� ����
    //initData�� ���۸� �ʱ�ȭ�� �� �ִ�.
}