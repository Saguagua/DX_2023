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
	//�Է� ���̾ƿ��̸�, �Է� �������� ������ �����ϴ� ���� ���� ����
	//���ؽ� �����͸� ���̴��� ������ �� ����ϸ�, �� ���ؽ� �Ӽ��� �̸�, �ε���, ���� ���� �����Ѵ�.
	ComPtr<ID3D11VertexShader> _vertexShader;
};

