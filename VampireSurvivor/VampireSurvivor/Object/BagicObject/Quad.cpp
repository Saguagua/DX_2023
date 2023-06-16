#include "framework.h"
#include "Quad.h"

void Quad::Render()
{
	_vBuffer->SetIA_VertexBuffer();
	_iBuffer->SetIA_IndexBuffer();
	_vShader.lock()->SetIA_InputLayOut();
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_vShader.lock()->Set();
	_pShader.lock()->Set();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::Update()
{}