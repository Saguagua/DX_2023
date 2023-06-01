#pragma once
class Quad
{
public:
	Quad(UINT slot = 0);
	Quad(wstring path, UINT slot = 0);

	void Init();

	void Update();
	void Render();

	void TextureRender();

	void CreateVertices();
	void CreateData();

	void CreateTextureVertices();
	void CreateTextureData(wstring path);

	shared_ptr<Transform> GetTransform();

private:
	int _slot = 0;

	shared_ptr<Transform> _transform = make_shared<Transform>();
	vector<Vertex> _vertices;
	vector<int> _indexies;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;

	shared_ptr<SRV> _srv;
	shared_ptr<SamplerState> _sampler;

};

