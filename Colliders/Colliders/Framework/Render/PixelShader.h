#pragma once
class PixelShader
{
public:
	PixelShader(wstring path);
	~PixelShader();

	void Set_PS();

private:
	void CreateBlob(wstring path);
	void CreatePixelShader();
	ComPtr<ID3DBlob> pixelBlob;
	ComPtr<ID3D11PixelShader> ps;
};