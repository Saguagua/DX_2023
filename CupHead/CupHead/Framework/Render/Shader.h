#pragma once
class Shader
{
public:
	Shader(wstring path):_file(path) {}
	~Shader() {}

	virtual void Set() abstract;

protected:
	virtual void CreateBlob(wstring path) abstract;
	virtual void CreateShader() abstract;

	wstring _file;
	ComPtr<ID3DBlob> _blob;
};

