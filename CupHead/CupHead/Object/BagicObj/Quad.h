#pragma once
class Quad
{
public:
	Quad(wstring path);
	Quad(wstring path, Vector2 size);
	~Quad() {}

	void Render();

	void SetPS(shared_ptr<PixelShader> ps) { _pShader = ps; }
	void SetVS(shared_ptr<VertexShader> vs) { _vShader = vs; }
	
	Vector2 GetImageSize() { return _srv.lock()->GetImageSize(); }
private:
	void CreateVertices();
	void CreateData();

	vector<Vertex_Texture> _vertices;
	vector<int> _indices;

	shared_ptr<IndexBuffer> _iBuffer;
	shared_ptr<VertexBuffer> _vBuffer;

	weak_ptr<VertexShader> _vShader;
	weak_ptr<PixelShader> _pShader;

	weak_ptr<SRV> _srv;

	Vector2 _size;
};

