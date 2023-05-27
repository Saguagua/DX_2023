#pragma once
class VertexShader
{
public:
	VertexShader();
	~VertexShader();

	void CreateBlob();
	void CreateInputLayout();
	void CreateVertexShader();

	void SetIA_InputLayout();
	void Set_VertexShader();
private:
	ComPtr<ID3DBlob> _vertexBlob;
	ComPtr<ID3D11InputLayout> _inputLayout;
	//입력 레이아웃이며, 입력 데이터의 형식을 설명하는 설명서 같은 존재
	//버텍스 데이터를 세이더로 전달할 때 사용하며, 각 버텍스 속성의 이름, 인덱스, 형식 등을 정의한다.
	ComPtr<ID3D11VertexShader> _vertexShader;
};

