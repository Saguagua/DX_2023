#pragma once
class Quad
{
public:
	Quad(wstring path);
	~Quad();

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	void CreateVertex();
	

	shared_ptr<Transform> _transform;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _pBuffer;
	shared_ptr<VertexShader> _vShader;
	shared_ptr<PixelShader> _pShader;
	
	vector<Vertex> _vertices;
	vector<int> _indices;
};

