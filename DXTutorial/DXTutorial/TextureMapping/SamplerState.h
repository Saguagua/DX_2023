#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void CreateSampler();
	void SetSampler(UINT slot = 0);

private:
	ComPtr<ID3D11SamplerState> _samplerState;
};

