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
	//���� �������� ����, ���⼱ ���̴� ����Ʈ �ڵ带 ������ �뵵�� ���
	ComPtr<ID3D11PixelShader> _ps;
	//�ȼ� ���̴� ��ü�� ��Ƶ� ������
};

