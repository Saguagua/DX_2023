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
	void CreateInputLayout(wstring path);
	void CreateVertexShader();

	ComPtr<ID3DBlob> _vertexBlob;

	ComPtr<ID3D11InputLayout> _inputLayOut;
	ComPtr<ID3D11VertexShader> _vertexShader;
};