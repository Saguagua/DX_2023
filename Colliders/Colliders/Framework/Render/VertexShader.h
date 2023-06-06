#pragma once
class VertexShader
{
public:
	VertexShader(wstring path);
	~VertexShader();

	void SetIA_InputLayOut();
	void Set_VS();

private:
	void CreateBlob(wstring path);
	void CreateInputLayout();
	void CreateVertexShader();

	ComPtr<ID3DBlob> vertexBlob;

	ComPtr<ID3D11InputLayout> inputLayOut;
	ComPtr<ID3D11VertexShader> vertexShader;
};