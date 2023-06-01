#pragma once
class Square
{
public:
	Square();
	~Square();

	void CreateVertex();
	void Init();

private:
	// 인스턴스 데이터 생성 필요
	// 다 만든 인스턴스 데이터를 
	
	shared_ptr<VertexShader> vs;
	shared_ptr<PixelShader> ps;

};

