#include "framework.h"
#include "Line.h"

Line::Line()
{
	CreateVertex();
	CreateData();
}

Line::~Line()
{
}

void Line::CreateVertex()
{
	Vertex v;

	v.pos = {0.0f, 1.0f, 0.0f};
	v.color = {1.0f, 0.0f, 1.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
	_vertices.push_back(v);

	v.pos = { 0.0f, -1.0f, 0.0f };
	v.color = {1.0f, 0.0f, 1.0f, 1.0f };
	v.uv = { -1.0f, -1.0f };
	_vertices.push_back(v);
}

void Line::CreateData()
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
	_vertexShader = make_shared<VertexShader>();
	_pixelShader = make_shared<PixelShader>();
}

void Line::Render()
{
	_vertexBuffer->SetIA_VertexBuffer();
	_vertexShader->SetIA_InputLayout();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	_vertexShader->Set_VertexShader();
	_pixelShader->Set_PixelShader();

	DEVICECONTEXT->Draw(2, 0);
}

void Line::Update()
{
}
