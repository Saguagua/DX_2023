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
	//ù ��° : ������ hlsl ���� �˻縦 Ȱ��ȭ
	//�� ��° : ����� ������ ������ ���̴��� ������, (����� �� ���̴� �ڵ� ������ ����)
	// | ������ �̹Ƿ� �� ��� �� ����ϰڴٴ� ��

	D3DCompileFromFile(L"Shader/TutorialPixelShader.hlsl",
		nullptr, nullptr, "PS", "ps_5_0", flags, 0, _pixelBlob.GetAddressOf(), nullptr);
	//DX���� hlsl �ڵ带 �������ϴ� �Լ�, "PS"�� �ش� ������ ������ �Լ�, ps_5_0�� ����
	//�ش� �Լ��� ȣ���� pixelBlob�� �����ϵ� ���̴��� ����Ʈ �ڵ带 �����ϴ°� ����Ʈ��.
}

void PixelShader::CreatePixelShader()
{
	DEVICE->CreatePixelShader(_pixelBlob->GetBufferPointer(),
		_pixelBlob->GetBufferSize(), nullptr, IN _ps.GetAddressOf());
	//�ȼ����̴� ���� �Լ�
	//1���� ���̴� ����Ʈ �ڵ带 ����Ű�� ������, 2���� ����Ʈ �ڵ��� ����
	//�ش� �Լ��� ps�� ������ �ȼ� ���̴� ��ü�� �����͸� �����Ѵ�.
}

void PixelShader::Set_PixelShader()
{
	DEVICECONTEXT->PSSetShader(_ps.Get(), nullptr, 0);
	//������ �ȼ� ���̴��� ����ϴ� �Լ�
}
