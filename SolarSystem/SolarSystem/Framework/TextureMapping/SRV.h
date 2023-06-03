#pragma once
class SRV
{
public:
	SRV(wstring path);
	~SRV();

	void SetSRV(UINT slot = 0);

	Vector2<float> GetImageSize() { return _imageSize; }

private:
	Vector2<float> _imageSize;

	ComPtr<ID3D11ShaderResourceView> _srv;
};

