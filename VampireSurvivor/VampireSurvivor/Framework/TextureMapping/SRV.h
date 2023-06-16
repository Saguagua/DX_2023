#pragma once
class SRV
{
public:
	SRV(wstring path);
	~SRV() {}

	void SetSRV(UINT slot = 0) { DC->PSSetShaderResources(slot, 1, _srv.GetAddressOf()); }
	Vector2 GetImageSize() { return _imageSize; }

private:
	Vector2 _imageSize;
	ComPtr<ID3D11ShaderResourceView> _srv;
};

