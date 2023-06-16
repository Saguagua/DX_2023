#pragma once
class VertexShader : public Shader
{
public:
	VertexShader(wstring path);
	~VertexShader();

	void SetIA_InputLayOut();
	virtual void Set() override;

private:
	void CreateBlob(wstring path);
	void CreateInputLayout(wstring path);
	void CreateVertexShader();

	ComPtr<ID3D11InputLayout> _inputLayOut;
	ComPtr<ID3D11VertexShader> _vertexShader;

};