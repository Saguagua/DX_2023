#include "framework.h"
#include "Quad.h"

Quad::Quad()
{
	CreateVertices();
	CreateData();
}

Quad::Quad(wstring path)
{
}

void Quad::Update()
{
}

void Quad::Render()
{
	_vertexBuffer->SetIA_VertexBuffer();
	_vertexShader->SetIA_InputLayout();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_vertexShader->Set_VertexShader();
	_pixelShader->Set_PixelShader();

	DEVICECONTEXT->Draw(3, 0);
}

//������ �����ϰ� ����
//ȭ�� ��� ������ 0,0���� ������ ������.
void Quad::CreateVertices()
{
	Vertex v;
	v.pos = { -0.5f, 0.5f, 0.0f };
	v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
	_vertices.push_back(v);

	v.pos = { 0.5f, 0.5f, 0.0f };
	v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
	_vertices.push_back(v);

	v.pos = { -0.5f, -0.5f, 0.0f };
	v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
	_vertices.push_back(v);

}

void Quad::CreateData()
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_vertexShader = make_shared<VertexShader>();
	_pixelShader = make_shared<PixelShader>();
}
