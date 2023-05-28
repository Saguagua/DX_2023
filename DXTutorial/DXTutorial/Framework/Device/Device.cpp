#include "framework.h"
#include "Device.h"

Device* Device::_instance = nullptr;

Device::Device()
{
	CreateDeviceAndSwapChain();
	CreateDoubleBuffer();
}

Device::~Device()
{
}

void Device::Clear()
{
	FLOAT myColorR = 0.0f;
	FLOAT myColorG = 0.0f;
	FLOAT myColorB = 0.0f;

	FLOAT clearColor[4] = { myColorR, myColorG, myColorB, 1.0f };

	_deviceContext->ClearRenderTargetView(_renderTargetView.Get(), clearColor);
	//���� Ÿ���� ���ϴ� �������� �ʱ�ȭ
}

void Device::Present()
{
	_swapChain->Present(0, 0);
	//1. ���� ����ȭ ����, 0�̸� ��� �׸���
	//2. present ���ۿ� ���� �÷��׸� ����
}

//����̽�, ���ؽ�Ʈ, ����ü�� �����ϴ� �Լ�
void Device::CreateDeviceAndSwapChain()
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	//������ Ŭ���̾�Ʈ ������ ũ�⸦ ������ ����
	
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	//����̽� ������ �� �� �պ��� ��ġ�� �������� �˻���

	UINT featureSize = ARRAYSIZE(featureLevels);
	//�迭�� ����� �����ϴ� ����

	DXGI_SWAP_CHAIN_DESC sd = {};
	//�� ����ü�� ���� ü���� ������ �� �ʿ��� ������ ��´�.
	sd.BufferCount = 1;
	//���� ü���� �ĸ� ���� ����
	sd.BufferDesc.Width = WIN_WIDTH;
	sd.BufferDesc.Height = WIN_HEIGHT;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//���� ü���� �ĸ� ������ �ȼ� ������ ����
	//R8G8B8A8�̹Ƿ� �� ������ 8��Ʈ, _UNROM�� ��ȣ���� ����ȭ�� ������ �ȼ� ���� ǥ���Ѵ�.
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	// Numerator / Denominator => ȭ�� ������ ���� �ӵ�
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	//���� ü���� ���� ��� �뵵�� �����ϴ� �ڵ�
	//������ ���� Ÿ������ ���ȴ�.
	//���� Ÿ���� �׷��� ����̽��� ���� ������ �۾��� ����� ����Ǵ� ���۸� ����
	sd.OutputWindow = hWnd;
	//���� ü���� ǥ���� â�� ����
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	//���� ü���� ��Ƽ���ø� ������ ��Ÿ���� �ڵ�
	//��Ƽ���ø��� ������ ������ �ȼ��� �� �����ϰ� ���ø��� �ε巴�� �Ѵ�.
	sd.Windowed = true; // â���

	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		0,
		D3D11_CREATE_DEVICE_DEBUG,
		featureLevels,
		featureSize,
		D3D11_SDK_VERSION,
		&sd,
		IN _swapChain.GetAddressOf(),
		IN _device.GetAddressOf(),		//GetAddressOf() ComPtr �������� ���� ������ ��ȯ
		nullptr,
		IN _deviceContext.GetAddressOf() //IN Ű����� �б� ���� �Ű�������� ��
	);
	//����̽�, ����̽����ؽ�Ʈ, ����ü���� �����ϴ� �Լ�
	//������ ��ü���� �Ű� ������ ����
	//swapChain, _device, _deviceContex�� �����Ѵ�. 
}

//����� ����, ���� Ÿ�� �� ����
//������ ���� Ÿ�� �並 �����ϰ� ����Ʈ�� ����, ����
void Device::CreateDoubleBuffer()
{
	ComPtr<ID3D11Texture2D> backBuffer;

	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
	// ������ �ε����� �ش��ϴ� �ĸ� ���۸� 3��° �Ű������� backBuffer�� �����ϴ� �Լ�
	// 0�� ����� ù ��° �ĸ� ���۸� �����´�.
	_device->CreateRenderTargetView(backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf());
	//������ ������ ����۸� ������� �� ���� Ÿ�� �䰡 _renderTargetView�� ����
	_deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), nullptr);
	// ���� Ÿ�� �並 ��� �����Ϳ� ���ε�
	// OM : Output Merger
	// ��� �����Ϳ� ���ε��Ѵ� : ��� ���� �ܰ迡�� ����� ���� Ÿ�� �� ���� ���ٽ� ���۸� �����Ѵ�.
	
	D3D11_VIEWPORT vp;
	vp.Width = WIN_WIDTH;
	vp.Height = WIN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	_deviceContext->RSSetViewports(1, &vp);

	//����Ʈ�� �����ϰ� ���ؽ�Ʈ�� ���
	//���ؽ�Ʈ�� ����Ʈ�� �������� �����Ѵ�.
}