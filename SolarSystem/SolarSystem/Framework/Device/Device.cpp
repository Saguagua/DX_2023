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

void Device::Create()
{
	if (_instance == nullptr)
		_instance = new Device();
}

void Device::Delete()
{
	if (_instance != nullptr)
		delete _instance;
}

Device* Device::GetInstance()
{
	if (_instance != nullptr)
		return _instance;

	return nullptr;
}

ComPtr<ID3D11Device> Device::GetDevice()
{
	return _device;
}

ComPtr<ID3D11DeviceContext> Device::GetContext()
{
	return _context;
}

void Device::Clear()
{
	FLOAT R = 0.0f;
	FLOAT G = 0.0f;
	FLOAT B = 0.0f;

	FLOAT clearColor[4] = { R,G,B,1.0f };

	_context->ClearRenderTargetView(_renderTargetView.Get(), clearColor);
}

void Device::Present()
{
	_swapChain->Present(0,0);
}

void Device::CreateDeviceAndSwapChain()
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	UINT width = WIN_WIDTH;
	UINT height = WIN_HEIGHT;

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};

	UINT featureSize = ARRAYSIZE(featureLevels);
	
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	// Numerator / Denominator => ȭ�� ������ ���� �ӵ�
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
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
		IN _device.GetAddressOf(),
		nullptr,
		IN _context.GetAddressOf()
	);
}

void Device::CreateDoubleBuffer()
{
	ComPtr<ID3D11Texture2D> backBuffer;

	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
	_device->CreateRenderTargetView(backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf());
	_context->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), nullptr);
	
	D3D11_VIEWPORT vp;
	vp.Width = WIN_WIDTH;
	vp.Height = WIN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	_context->RSSetViewports(1, &vp);
}
