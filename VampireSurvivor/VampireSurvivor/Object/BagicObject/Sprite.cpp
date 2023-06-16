#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring path)
	:Quad()
{
    _srv = SRVManager::GetInstance()->AddSRV(path);
    _size = _srv.lock()->GetImageSize();
    _actionBuffer = make_shared<ActionBuffer>();
    _actionBuffer->SetFullSize(_size);

    CreateVertex();
    CreateData();
}

Sprite::Sprite(wstring path, Vector2 size)
	:Quad(size)
{
    _srv = SRVManager::GetInstance()->AddSRV(path);
    _actionBuffer = make_shared<ActionBuffer>();
    _actionBuffer->SetFullSize(_size);

    CreateVertex();
    CreateData();
}

void Sprite::Update()
{
    _actionBuffer->UpdateData();
    Quad::Update();
}

void Sprite::Render()
{
    _actionBuffer->SetPS_Buffer(0);
    Quad::Render();
}

void Sprite::CreateVertex()
{
	Vertex_Texture v;

	Vector2 halfSize = _size * 0.5f;

	v.pos = { -halfSize.x, halfSize.y, 0.0f };
	v.uv = { 0, 0 };
	_vertices.push_back(v);

	v.pos = { halfSize.x, halfSize.y, 0.0f };
	v.uv = { 1, 0 };
	_vertices.push_back(v);

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

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

void Sprite::CreateData()
{
    _vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
    _iBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
    _vShader = ShaderManager::GetInstance()->Add_VertexShader(L"Shader/TextureVS.hlsl");
    _pShader = ShaderManager::GetInstance()->AddPixelShader(L"Shader/ActionPS.hlsl");
}
