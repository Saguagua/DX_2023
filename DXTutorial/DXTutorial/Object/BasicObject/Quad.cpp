#include "framework.h"
#include "Quad.h"

Quad::Quad()
{
	CreateVertices();
	CreateData();
}

Quad::Quad(wstring path)
{
	CreateTextureVertices(path);
	CreateTextureData(path);
}

void Quad::Update()
{
}

void Quad::Render()
{
	_vertexBuffer->SetIA_VertexBuffer();
	_indexBuffer->SetIA_IndexBuffer();
	_vertexShader->SetIA_InputLayout();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_vertexShader->Set_VertexShader();
	_pixelShader->Set_PixelShader();

	DEVICECONTEXT->DrawIndexed(_indexies.size(), 0, 0);
}

void Quad::TextureRender()
{
	_vertexBuffer->SetIA_VertexBuffer();
	_indexBuffer->SetIA_IndexBuffer();
	_vertexShader->SetIA_InputLayout();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv->SetSRV();
	_sampler->SetSampler();

	_vertexShader->Set_VertexShader();
	_pixelShader->Set_PixelShader();

	DEVICECONTEXT->DrawIndexed(_indexies.size(), 0, 0);
}

//정점들 생성하고 저장
//화면 가운데 기준을 0,0으로 비율로 따진다.
void Quad::CreateVertices()
{
	Vertex v;
	v.pos = { -0.5f, 0.5f, 0.0f };        //왼 위
	v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
	v.uv = {-1.0f, -1.0f};
	_vertices.push_back(v);

	v.pos = { 0.5f, 0.5f, 0.0f };         //오 위
	v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
	_vertices.push_back(v);

	v.pos = { 0.5f, -0.5f, 0.0f };        //오 아
	v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
	_vertices.push_back(v);

	v.pos = { -0.5f, -0.5f, 0.0f };       //왼 아
	v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
	_vertices.push_back(v);

	_indexies.push_back(0);
	_indexies.push_back(1);
	_indexies.push_back(2);
	_indexies.push_back(0);
	_indexies.push_back(2);
	_indexies.push_back(3);
}

void Quad::CreateData()
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indexies.data(), _indexies.size());
	_vertexShader = make_shared<VertexShader>();
	_pixelShader = make_shared<PixelShader>();
}

void Quad::CreateTextureVertices(wstring path)
{
	Vertex v;
	v.pos = { 0.0f, 250.0f, 0.0f }; // 왼쪽 위
	v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
	v.uv = { 0.0f, 0.0f };
	_vertices.push_back(v);

	v.pos = { 250.0f, 250.0f, 0.0f }; // 오른쪽 위
	v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
	v.uv = { 1.0f, 0.0f };
	_vertices.push_back(v);

	v.pos = { 250.0f, 0.0f, 0.0f }; // 오른쪽 아래
	v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
	v.uv = { 1.0, 1.0f };
	_vertices.push_back(v);

	v.pos = { 0.0f, 0.0f, 0.0f }; // 왼쪽 아래
	v.color = { 0.0f, 0.0f, 0.0f, 1.0f };
	v.uv = { 0.0f, 1.0f };
	_vertices.push_back(v);

	_indexies.push_back(0);
	_indexies.push_back(1);
	_indexies.push_back(2);

	_indexies.push_back(0);
	_indexies.push_back(2);
	_indexies.push_back(3);
}

void Quad::CreateTextureData(wstring path)
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indexies.data(), _indexies.size());
	_vertexShader = make_shared<VertexShader>();
	_pixelShader = make_shared<PixelShader>();

	_srv = make_shared<SRV>(path);
	_sampler = make_shared<SamplerState>();
}
