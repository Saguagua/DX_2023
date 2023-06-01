#include "framework.h"
#include "Quad.h"

Quad::Quad()
{
	CreateVertices();
	CreateData();
	Init();
}

Quad::Quad(wstring path)
{
	CreateTextureVertices(path);
	CreateTextureData(path);
	Init();
}

void Quad::Init()
{
	_transform->SetBuffer(0);
	_vertexBuffer->SetIA_VertexBuffer();
	_indexBuffer->SetIA_IndexBuffer();
	_vertexShader->SetIA_InputLayout();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv->SetSRV();
	_sampler->SetSampler();

	_vertexShader->Set_VertexShader();
	_pixelShader->Set_PixelShader();
}

void Quad::Update()
{
	_transform->UpdateSRT();
	_transform->UpdateBuffer();
}

void Quad::Render()
{
	DEVICECONTEXT->DrawIndexed(_indexies.size(), 0, 0);
}

void Quad::TextureRender()
{
	DEVICECONTEXT->DrawIndexed(_indexies.size(), 0, 0);
}



void Quad::CreateData()
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indexies.data(), _indexies.size());
	_vertexShader = make_shared<VertexShader>();
	_pixelShader = make_shared<PixelShader>();
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

//정점들 생성하고 저장
//화면 가운데 기준을 0,0으로 비율로 따진다.
void Quad::CreateVertices()
{
	Vertex v;
	v.pos = { -0.5f, 0.5f, 0.0f };        //왼 위
	v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
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



void Quad::Scale(Vector2<float> other)
{
	_transform->AddScale(other);
}

void Quad::Rotate(float angle)
{
	_transform->AddAngle(angle);
}

void Quad::Translate(Vector2<float> other)
{
	_transform->AddPos(other);
}

void Quad::ShapeChange(vector<Vertex>* other)
{
	_vertexBuffer->SetBuffer(other);
}

void Quad::DrawChange(vector<int>* other)
{
	_indexBuffer->SetBuffer(other);
}
