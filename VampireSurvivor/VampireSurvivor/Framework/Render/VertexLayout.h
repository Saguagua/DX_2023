#pragma once
#include "../../framework.h"

struct Vertex
{
    XMFLOAT3 pos = { 0.0f,0.0f,0.0f };
};

struct Vertex_Color : public Vertex
{
    XMFLOAT4 color = { 0.0f, 0.0f, 0.0f, 0.0f };
};

struct Vertex_Texture : public Vertex
{
    XMFLOAT2 uv = { 0.0f, 0.0f };
};