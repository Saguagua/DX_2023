#pragma once
class Line
{
public:
	Line();
	~Line();

	void CreateVertex();
	void CreateData();

	void Render();
	void Update();

private:
	vector<Vertex> _vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;
};

