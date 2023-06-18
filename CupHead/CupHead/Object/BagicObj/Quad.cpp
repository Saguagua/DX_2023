#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring path)
{
	_srv = ADD_SRV(path);
	_size = _srv.lock()->GetImageSize();

	CreateVertices();
	CreateData();
}

Quad::Quad(wstring path, Vector2 size)
{
	_srv = ADD_SRV(path);
	_size = size;

	CreateVertices();
	CreateData();
}

void Quad::Render()
{
	_vBuffer->SetIA_VertexBuffer();
	_iBuffer->SetIA_IndexBuffer();
	_vShader.lock()->SetIA_InputLayout();

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv.lock()->SetSRV(0);
	SAMPLER->SetSampler();

	_vShader.lock()->Set();
	_pShader.lock()->Set();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::CreateVertices()
{
    Vertex_Texture v;

    Vector2 halfSize = _size * 0.5f;

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, halfSize.y, 0.0f }; // 오른쪽 위
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
    v.uv = { 1.0, 1.0f };
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

void Quad::CreateData()
{
    _vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
    _iBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
    _vShader = ADD_VS(L"Shader/TextureVS.hlsl");
    _pShader = ADD_PS(L"Shader/TexturePS.hlsl");
}
