#pragma once
class Square
{
public:
	Square();
	~Square();

	void CreateVertex();
	void Init();

private:
	// �ν��Ͻ� ������ ���� �ʿ�
	// �� ���� �ν��Ͻ� �����͸� 
	
	shared_ptr<VertexShader> vs;
	shared_ptr<PixelShader> ps;

};

