#pragma once
class Quad
{
public:
	Quad();
	Quad(wstring path);

	void Update();
	void Render();

	void CreateVertices();
	void CreateData();

private:
	vector<Vertex> _vertices;
	
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;

};

