#pragma once
class Quad
{
public:
	Quad();
	Quad(wstring path);

	void Init();

	void Update();
	void Render();

	void TextureRender();

	void CreateVertices();
	void CreateData();

	void CreateTextureVertices(wstring path);
	void CreateTextureData(wstring path);

	void Scale(Vector2<float> other);
	void Rotate(float angle);
	void Translate(Vector2<float> other);

	void ShapeChange(vector<Vertex>* other);
	void DrawChange(vector<int>* other);

private:
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

