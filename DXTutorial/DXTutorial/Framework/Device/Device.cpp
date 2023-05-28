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
	//렌더 타겟을 원하는 색상으로 초기화
}

void Device::Present()
{
	_swapChain->Present(0, 0);
	//1. 수직 동기화 간격, 0이면 즉시 그리기
	//2. present 동작에 대한 플래그를 지정
}

//디바이스, 컨텍스트, 스왑체인 생성하는 함수
void Device::CreateDeviceAndSwapChain()
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	//윈도우 클리이언트 영역의 크기를 가져와 저장
	
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	//디바이스 생성할 때 맨 앞부터 위치한 버젼부터 검사함

	UINT featureSize = ARRAYSIZE(featureLevels);
	//배열의 사이즈를 저장하는 변수

	DXGI_SWAP_CHAIN_DESC sd = {};
	//위 구조체는 스왑 체인을 생성할 때 필요한 정보를 담는다.
	sd.BufferCount = 1;
	//스왑 체인의 후면 버퍼 개수
	sd.BufferDesc.Width = WIN_WIDTH;
	sd.BufferDesc.Height = WIN_HEIGHT;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//스왑 체인의 후면 버퍼의 픽셀 형식을 설정
	//R8G8B8A8이므로 각 색상이 8비트, _UNROM은 부호없는 정규화된 값으로 픽셀 색상 표현한다.
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	// Numerator / Denominator => 화면 프레임 갱신 속도
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	//스왑 체인의 버퍼 사용 용도를 설정하는 코드
	//위에선 렌더 타겟으로 사용된다.
	//렌더 타겟은 그래픽 디바이스에 의해 렌더링 작업의 결과가 저장되는 버퍼를 뜻함
	sd.OutputWindow = hWnd;
	//스왑 체인이 표시할 창을 지정
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	//스왑 체인의 멀티샘플링 설정을 나타내는 코드
	//멀티샘플링은 렌더링 과정에 픽셀을 더 정교하게 샘플링해 부드럽게 한다.
	sd.Windowed = true; // 창모드

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
		IN _device.GetAddressOf(),		//GetAddressOf() ComPtr 변수들의 더블 포인터 반환
		nullptr,
		IN _deviceContext.GetAddressOf() //IN 키워드는 읽기 전용 매개변수라는 뜻
	);
	//디바이스, 디바이스컨텍스트, 스왑체인을 생성하는 함수
	//생성된 객체들을 매개 변수로 넣은
	//swapChain, _device, _deviceContex에 연결한다. 
}

//백버퍼 생성, 렌더 타겟 뷰 생성
//생성된 렌더 타겟 뷰를 세팅하고 뷰포트를 생성, 세팅
void Device::CreateDoubleBuffer()
{
	ComPtr<ID3D11Texture2D> backBuffer;

	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
	// 지정된 인덱스에 해당하는 후면 버퍼를 3번째 매개변수인 backBuffer에 저장하는 함수
	// 0을 사용해 첫 번째 후면 버퍼를 가져온다.
	_device->CreateRenderTargetView(backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf());
	//위에서 생성된 백버퍼를 대상으로 한 렌더 타겟 뷰가 _renderTargetView에 저장
	_deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), nullptr);
	// 렌더 타겟 뷰를 출력 마스터에 바인딩
	// OM : Output Merger
	// 출력 마스터에 바인딩한다 : 출력 병합 단계에서 사용할 렌더 타겟 및 깊이 스텐실 버퍼를 설정한다.
	
	D3D11_VIEWPORT vp;
	vp.Width = WIN_WIDTH;
	vp.Height = WIN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	_deviceContext->RSSetViewports(1, &vp);

	//뷰포트를 설정하고 컨텍스트에 등록
	//컨텍스트는 뷰포트에 렌더링을 수행한다.
}