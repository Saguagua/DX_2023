#pragma once
class Quad
{
protected:
	Quad() {}
public:
	Quad(wstring path, wstring shader = L"Shader/TexturePS.hlsl");
	Quad(wstring path, Vector2 size, wstring shader = L"Shader/TexturePS.hlsl");
	virtual ~Quad() {}

	Vector2 GetSize();

	virtual void Update();
	virtual void Render();

	virtual void CreateVertices();
	virtual void CreateData(wstring path);

protected:
	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;

	Vector2 _size;
};