#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring path)
{
    CreateBlob(path);
    CreateInputLayout(path);
    CreateVertexShader();
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateBlob(wstring path)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    D3DCompileFromFile(path.c_str(),
        nullptr, nullptr, "VS", "vs_5_0", flags, 0, _blob.GetAddressOf(), nullptr);
}

void VertexShader::CreateInputLayout(wstring path)
{
    D3D11_INPUT_ELEMENT_DESC layOut[2];

    if (path == L"Shader/ColorVS.hlsl")
    {
        layOut[0] = {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        };
        layOut[1] = {
            "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
                D3D11_INPUT_PER_VERTEX_DATA, 0
        };
    }
    else if (path == L"Shader/TextureVS.hlsl")
    {
        layOut[0] = {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        };
        layOut[1] = {
                    "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,
                        D3D11_INPUT_PER_VERTEX_DATA, 0
        };;

    }
    else if (path == L"Shader/VertexVS.hlsl")
    {
        layOut[0] = {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        };
    }

    UINT layOutSize = ARRAYSIZE(layOut);

    DEVICE->CreateInputLayout(layOut, layOutSize,
        _blob->GetBufferPointer(), _blob->GetBufferSize(), IN _inputLayOut.GetAddressOf());
}

void VertexShader::CreateVertexShader()
{
    DEVICE->CreateVertexShader(_blob->GetBufferPointer(),
        _blob->GetBufferSize(), nullptr, IN _vertexShader.GetAddressOf());
}

void VertexShader::Set()
{
    DC->VSSetShader(_vertexShader.Get(), nullptr, 0);
}

void VertexShader::SetIA_InputLayOut()
{
    DC->IASetInputLayout(_inputLayOut.Get());
}