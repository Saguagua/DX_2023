#pragma once
class PixelShader
{
public:
	PixelShader();
	~PixelShader();

	void CreateBlob();
	void CreatePixelShader();

	void Set_PixelShader();
private:
	ComPtr<ID3DBlob> _pixelBlob;
	//이진 데이터의 버퍼, 여기선 셰이더 바이트 코드를 저장할 용도로 사용
	ComPtr<ID3D11PixelShader> _ps;
	//픽셀 셰이더 객체를 담아둘 포인터
};

