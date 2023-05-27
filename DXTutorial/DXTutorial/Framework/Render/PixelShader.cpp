#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader()
{
	CreateBlob();
	CreatePixelShader();
}

PixelShader::~PixelShader()
{
}

void PixelShader::CreateBlob()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	//첫 번째 : 엄격한 hlsl 문법 검사를 활성화
	//두 번째 : 디버그 정보를 포함해 셰이더를 컴파일, (디버깅 중 셰이더 코드 추적이 가능)
	// | 연산자 이므로 두 기능 다 사용하겠다는 뜻

	D3DCompileFromFile(L"Shader/TutorialPixelShader.hlsl",
		nullptr, nullptr, "PS", "ps_5_0", flags, 0, _pixelBlob.GetAddressOf(), nullptr);
	//DX에서 hlsl 코드를 컴파일하는 함수, "PS"는 해당 파일의 진입점 함수, ps_5_0은 버젼
	//해당 함수를 호출해 pixelBlob에 컴파일된 셰이더의 바이트 코드를 저장하는게 포인트다.
}

void PixelShader::CreatePixelShader()
{
	DEVICE->CreatePixelShader(_pixelBlob->GetBufferPointer(),
		_pixelBlob->GetBufferSize(), nullptr, IN _ps.GetAddressOf());
	//픽셀셰이더 생성 함수
	//1번은 셰이더 바이트 코드를 가리키는 포인터, 2번은 바이트 코드의 길이
	//해당 함수로 ps에 생성된 픽셀 셰이더 객체의 포인터를 저장한다.
}

void PixelShader::Set_PixelShader()
{
	DEVICECONTEXT->PSSetShader(_ps.Get(), nullptr, 0);
	//생성된 픽셀 셰이더를 등록하는 함수
}
