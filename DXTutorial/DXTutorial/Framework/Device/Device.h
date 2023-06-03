#pragma once
class Device
{
private:
	Device();
	~Device();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Device();
	}

	static void Delete() 
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Device* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	ComPtr<ID3D11Device> GetDevice() { return _device; }
	ComPtr<ID3D11DeviceContext> GetContext() { return _deviceContext; }

	void Clear();
	void Present();

private:
	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();
	static Device* _instance;

	ComPtr<ID3D11Device> _device;				
	// �׷��� ����̽��� ����, ����
	ComPtr<ID3D11DeviceContext> _deviceContext;  
	// �׷��� ����̽��� �۾��� ����
	ComPtr<IDXGISwapChain> _swapChain;
	// �ĸ� ���۸� �����ϰ� ȭ�鿡 �������ϴ� �� ���
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// ������ ����� ����ϱ� ���� ���� Ÿ�� �並 ��Ÿ����.
	// ���� Ÿ�� ��� �ĸ� ���ۿ� ���� ������ ����� ����, ȭ�鿡 ǥ���ϴ� �� ���
};
