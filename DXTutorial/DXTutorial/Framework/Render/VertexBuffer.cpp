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
    //입력 어셈블러에 사용 될 버텍스 버퍼를 설정하는 함수
    //매개변수
    //1. 설정을 시작할 슬롯
    //2. 설정할 버퍼의 개수
    //3. 버퍼의 인터페이스 포인터 배열을 나타내는 이중 포인터
    //4. 각 버퍼의 버텍스 크기
    //5. 각 버퍼의 오프셋
    
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
    //버퍼 객체를 생성하기 위한 구조체
    _bd.Usage = D3D11_USAGE_DEFAULT;
    _bd.ByteWidth = _stride * _count;
    _bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    //버퍼나 텍스처와 같은 리소스 데이터를 초기화하기 위한 구조체
    _initData.pSysMem = _data;
    //초기화할 데이터가 있는 포인터

    DEVICE->CreateBuffer(&_bd, &_initData, IN _vertexBuffer.GetAddressOf());
    //버퍼 생성함수
    //bd로 크기, 사용법, 바인딩 플래그 등을 지정
    //initData로 버퍼를 초기화할 수 있다.
}