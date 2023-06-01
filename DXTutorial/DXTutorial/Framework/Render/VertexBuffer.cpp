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

void VertexBuffer::SetBuffer(vector<Vertex>* other)
{
    _data = other;

    _bd.ByteWidth = sizeof(*other) * other->size();
    _initData.pSysMem = _data;

    DEVICE->CreateBuffer(&_bd, &_initData, IN _vertexBuffer.GetAddressOf());
}

void VertexBuffer::CreateVertexBuffer()
{
    //���� ��ü�� �����ϱ� ���� ����ü
    _bd.Usage = D3D11_USAGE_DEFAULT;
    _bd.ByteWidth = _stride * _count;
    _bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    //���۳� �ؽ�ó�� ���� ���ҽ� �����͸� �ʱ�ȭ�ϱ� ���� ����ü
    _initData.pSysMem = _data;
    //�ʱ�ȭ�� �����Ͱ� �ִ� ������

    DEVICE->CreateBuffer(&_bd, &_initData, IN _vertexBuffer.GetAddressOf());
    //���� �����Լ�
    //bd�� ũ��, ����, ���ε� �÷��� ���� ����
    //initData�� ���۸� �ʱ�ȭ�� �� �ִ�.
}