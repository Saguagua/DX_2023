Texture2D resource : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};

float4 PS(PixelInput input) : SV_TARGET
{
	return input.color;
}