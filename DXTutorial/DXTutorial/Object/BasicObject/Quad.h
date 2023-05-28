#pragma once
class Quad
{
public:
	Quad();
	Quad(wstring path);

	void Update();
	void Render();

	void TextureRender();

	void CreateVertices();
	void CreateData();

	void CreateTextureVertices(wstring path);
	void CreateTextureData(wstring path);

private:
	vector<Vertex> _vertices;
	vector<int> _indexies;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;

	shared_ptr<SRV> _srv;
	shared_ptr<SamplerState> _sampler;
};

