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
	// 그래픽 디바이스를 생성, 관리
	ComPtr<ID3D11DeviceContext> _deviceContext;  
	// 그래픽 디바이스의 작업을 수행
	ComPtr<IDXGISwapChain> _swapChain;
	// 후면 버퍼를 관리하고 화면에 렌더링하는 데 사용
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// 렌더링 결과를 출력하기 위한 렌더 타겟 뷰를 나타낸다.
	// 렌더 타겟 뷰는 후면 버퍼에 대한 렌더링 결과를 저장, 화면에 표시하는 데 사용
};

