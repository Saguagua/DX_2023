Texture2D resource : register(t0); //GPU의 레지스터 -> 저장공간, t0번째 슬롯에 저장 (정보 전달)
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
}

float4 PS(PixelInput input) : SV_TARGET
{
	return resource.Sample(samp, input.uv);
}