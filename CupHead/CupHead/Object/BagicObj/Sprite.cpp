#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring path)
{
	_srv = ADD_SRV(path);
	_size = _srv.lock()->GetImageSize();

	_aBuffer = make_shared<ActionBuffer>();
	_aBuffer->SetFullSize(_size);

	CreateVertices();
	CreateData(path);
}

Sprite::Sprite(wstring path, Vector2 size)
{
	_srv = ADD_SRV(path);
	_size = size;

	_aBuffer = make_shared<ActionBuffer>();
	_aBuffer->SetFullSize(_srv.lock()->GetImageSize());
	
	CreateVertices();
	CreateData(path);
}

void Sprite::Render()
{
	_rBuffer->SetPS_Buffer(0);
	_aBuffer->SetPS_Buffer(1);
	_vBuffer->SetIA_VertexBuffer();
	_iBuffer->SetIA_IndexBuffer();
	_vs.lock()->SetIA_InputLayout();
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv.lock()->SetSRV(0);
	SAMPLER->SetSampler();

	_vs.lock()->Set();
	_ps.lock()->Set();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Sprite::Update()
{
	_rBuffer->Update_Resource();
	_aBuffer->Update_Resource();
}

void Sprite::SetCurClip(Action::Clip clip)
{
	_aBuffer->SetClipSize(clip.size);
	_aBuffer->SetStart(clip.startPos);
}

void Sprite::CreateVertices()
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

void Sprite::CreateData(wstring path)
{
	_vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
	_iBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
	_vs = ADD_VS(L"Shader/TextureVS.hlsl");
	_ps = ADD_PS(L"Shader/ActionFilterPS.hlsl");

	_rBuffer = make_shared<IntBuffer>();
}
