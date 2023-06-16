Texture2D resource : register(t0);
SamplerState samp : register(s0);

cbuffer ActionBuffer : register(b0)
{
	float2 startPos;
	float2 size;
	float2 imageSize;
	int padding[2];
};

struct Input
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(Input input) : SV_TARGET
{
	float2 resultUV;
	resultUV.x = (startPos.x) / (imageSize.x) + input.uv.x * (size.x / imageSize.x);
	resultUV.y = (startPos.y) / (imageSize.y) + input.uv.y * (size.y / imageSize.y);

	float4 color = resource.Sample(samp, resultUV);

	return color;
}