#pragma once
class PixelShader:public Shader
{
public:
	PixelShader(wstring path);
	~PixelShader();

	virtual void Set() override;
private:
	void CreateBlob(wstring path);
	void CreatePixelShader();

	ComPtr<ID3D11PixelShader> _pixelShader;

};