#pragma once
#include "framework.h"

struct Vertex
{
	XMFLOAT3 pos;
	XMFLOAT4 color;
	XMFLOAT2 uv;
	//XMFLOAT : DirectX Math 의 구조체로 뒤 숫자의 차원을 갖는다.
	//x,y에 동차좌표계 사용하니 + 1차원인 XMFLOAT3을 사용한 이유
	//color는 RGBA 여기서 A는 투명도
	//uv는 동차좌표를 사용할 이유 없으니 u와 v만
};