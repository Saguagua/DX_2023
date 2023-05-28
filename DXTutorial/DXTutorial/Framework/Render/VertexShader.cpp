#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader()
{
	CreateBlob();
	CreateInputLayout();
	CreateVertexShader();
}

VertexShader::VertexShader(wstring path)
{
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateBlob()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	D3DCompileFromFile(L"Shader/TutorialVertexShader.hlsl",
		nullptr, nullptr, "VS", "vs_5_0", flags, 0, _vertexBlob.GetAddressOf(), nullptr);
}

void VertexShader::CreateInputLayout()
{
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
			D3D11_INPUT_PER_VERTEX_DATA,0
		},
		{
			"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,
			D3D11_INPUT_PER_VERTEX_DATA,0
		},
		{
			"UV", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28,
			D3D11_INPUT_PER_VERTEX_DATA,0
		}
	};
	//입력 레이아웃을 정의하는 배열
	//매개변수
	//1.시멘틱 네임, 2. 시멘틱 이름 중복일 경우 구별 인덱스 
	//3. 데이터 형식 여기선 포지션이 4바이트 3개 컬러가 4바이트 4개라고 알려줌
	//4. 입력 슬롯(인덱스 버퍼와 구분하기 위한) 
	//5. 입력데이터의 오프셋 단위 포지션은 처음이니 시작인 0, 컬러는 포지션 다음에 오고 포지션이 총 12바이트니 12
	//6. 입력 데이터의 구분 방식 여기선 버텍스 단위로 입력이 이루어진다
	//7. 인스턴싱을 사용할 경우 인스터스 데이터의 간격

	UINT layoutSize = ARRAYSIZE(layout);

	DEVICE->CreateInputLayout(layout, layoutSize,
		_vertexBlob->GetBufferPointer(), _vertexBlob->GetBufferSize(), IN _inputLayout.GetAddressOf());
	//입력 레이아웃 개체를 생성하는 함수
}

void VertexShader::CreateTextureInputLayout()
{
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
			D3D11_INPUT_PER_VERTEX_DATA,0
		},
		{
			"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,
			D3D11_INPUT_PER_VERTEX_DATA,0
		}
	};

	UINT layoutSize = ARRAYSIZE(layout);

	DEVICE->CreateInputLayout(layout, layoutSize,
		_vertexBlob->GetBufferPointer(), _vertexBlob->GetBufferSize(), IN _inputLayout.GetAddressOf());
}

void VertexShader::CreateVertexShader()
{
	DEVICE->CreateVertexShader(_vertexBlob->GetBufferPointer(),
		_vertexBlob->GetBufferSize(), nullptr, IN _vertexShader.GetAddressOf());
}

void VertexShader::SetIA_InputLayout()
{
	DEVICECONTEXT->IASetInputLayout(_inputLayout.Get());
}

void VertexShader::Set_VertexShader()
{
	DEVICECONTEXT->VSSetShader(_vertexShader.Get(), nullptr, 0);
}
