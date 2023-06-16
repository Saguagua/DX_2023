#pragma once
class Shader
{
public:
	Shader() {}
	~Shader() {}

	virtual void Set() abstract;
protected:
	wstring _file;
	ComPtr<ID3DBlob> _blob;
};

