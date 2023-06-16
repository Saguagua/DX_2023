#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState() {}

	void SetSampler(UINT slot = 0);

private:
	void CreateState();
	ComPtr<ID3D11SamplerState> samplerState;
};

