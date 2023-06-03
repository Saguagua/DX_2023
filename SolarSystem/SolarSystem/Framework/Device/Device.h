#pragma once
class Device
{
private:
	Device();
	~Device();

public:
	static void Create();
	static void Delete();
	static Device* GetInstance();

	ComPtr<ID3D11Device> GetDevice();
	ComPtr<ID3D11DeviceContext> GetContext();

	void Clear();
	void Present();

private:
	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();

	static Device* _instance;

	ComPtr<ID3D11Device> _device;
	ComPtr<ID3D11DeviceContext> _context;
	ComPtr<IDXGISwapChain> _swapChain;
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
};

