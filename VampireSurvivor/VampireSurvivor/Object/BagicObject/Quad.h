#pragma once
class Quad
{
protected:
	Quad() {}
	Quad(Vector2 size):_size(size) {}
	virtual ~Quad() {}

public:
	virtual void Render();
	virtual void Update();

protected:
	virtual void CreateVertex() abstract;
	virtual void CreateData() abstract;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _iBuffer;
	weak_ptr<VertexShader> _vShader;
	weak_ptr<PixelShader> _pShader;

	weak_ptr<SRV> _srv;
	
	vector<Vertex> _vertices;
	vector<UINT> _indices;

	Vector2 _size;
};

