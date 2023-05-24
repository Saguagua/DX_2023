Texture2D resource : register(t0); //GPU의 레지스터 -> 저장공간, t0번째 슬롯에 저장
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float uv : UV;
}

auto PS(PixelInput input) : SV_TARGET
{
	return resource.Sample(samp. inp);
}