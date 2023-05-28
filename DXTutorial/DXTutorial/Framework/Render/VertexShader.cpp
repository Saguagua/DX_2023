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
	//�Է� ���̾ƿ��� �����ϴ� �迭
	//�Ű�����
	//1.�ø�ƽ ����, 2. �ø�ƽ �̸� �ߺ��� ��� ���� �ε��� 
	//3. ������ ���� ���⼱ �������� 4����Ʈ 3�� �÷��� 4����Ʈ 4����� �˷���
	//4. �Է� ����(�ε��� ���ۿ� �����ϱ� ����) 
	//5. �Էµ������� ������ ���� �������� ó���̴� ������ 0, �÷��� ������ ������ ���� �������� �� 12����Ʈ�� 12
	//6. �Է� �������� ���� ��� ���⼱ ���ؽ� ������ �Է��� �̷������
	//7. �ν��Ͻ��� ����� ��� �ν��ͽ� �������� ����

	UINT layoutSize = ARRAYSIZE(layout);

	DEVICE->CreateInputLayout(layout, layoutSize,
		_vertexBlob->GetBufferPointer(), _vertexBlob->GetBufferSize(), IN _inputLayout.GetAddressOf());
	//�Է� ���̾ƿ� ��ü�� �����ϴ� �Լ�
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
