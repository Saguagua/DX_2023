#pragma once
#include "framework.h"

struct Vertex
{
	XMFLOAT3 pos;
	XMFLOAT4 color;
	XMFLOAT2 uv;
	//XMFLOAT : DirectX Math �� ����ü�� �� ������ ������ ���´�.
	//x,y�� ������ǥ�� ����ϴ� + 1������ XMFLOAT3�� ����� ����
	//color�� RGBA ���⼭ A�� ����
	//uv�� ������ǥ�� ����� ���� ������ u�� v��
};