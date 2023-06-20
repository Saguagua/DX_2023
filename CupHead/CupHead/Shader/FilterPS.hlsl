Texture2D resource : register(t0);
SamplerState samp : register(s0);

cbuffer FilterBuffer : register(b0)
{
	int type;
	int val1;
	int val2;
	int val3;

	float2 imageSize;
	float2 redialCenter;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 Mosaic(float2 uv)
{
	float x = floor(uv.x * val1);
	float y = floor(uv.y * val1);

	float2 tmp;

	tmp.x = x / val1;
	tmp.y = y / val1;

	return resource.Sample(samp, tmp);
}

float4 Blur(float2 uv)
{
	float4 result = 0;

	if (val2 == 0)
		return resource.Sample(samp, uv);

	for (int i = 0; i < val2; i++)
	{
		float divX = (i + 1) / imageSize.x;
		float divY = (i + 1) / imageSize.y;

		result += resource.Sample(samp, float2(uv.x + divX, uv.y)); //¿À
		result += resource.Sample(samp, float2(uv.x - divX, uv.y)); //¿Þ
		result += resource.Sample(samp, float2(uv.x, uv.y + divY)); //¾Æ
		result += resource.Sample(samp, float2(uv.x, uv.y - divY)); //À§
	}

	result /= 4 * val2;

	return result;
}

float4 OctaBlur(float2 uv)
{
	float4 result = 0;

	if (val2 == 0)
		return resource.Sample(samp, uv);

	for (int i = 0; i < val2; i++)
	{
		float divX = (i + 1) / imageSize.x;
		float divY = (i + 1) / imageSize.y;

		result += resource.Sample(samp, float2(uv.x + divX, uv.y)); //¿À
		result += resource.Sample(samp, float2(uv.x - divX, uv.y)); //¿Þ
		result += resource.Sample(samp, float2(uv.x, uv.y + divY)); //¾Æ
		result += resource.Sample(samp, float2(uv.x, uv.y - divY)); //À§

		result += resource.Sample(samp, float2(uv.x + divX, uv.y - divY)); //¿ÀÀ§
		result += resource.Sample(samp, float2(uv.x - divX, uv.y - divY)); //¿ÞÀ§
		result += resource.Sample(samp, float2(uv.x + divX, uv.y - divY)); //¿À¾Æ
		result += resource.Sample(samp, float2(uv.x - divX, uv.y - divY)); //¿Þ¾Æ
	}

	result /= 8 * val2;

	return result;
}

float4 PS(PixelInput input) : SV_TARGET
{
	[branch]
	if (type == 0)
		return resource.Sample(samp, input.uv);
	else if (type == 1)
		return Mosaic(input.uv);
	else if (type == 2)
		return Blur(input.uv);
	else if (type == 3)
		return OctaBlur(input.uv);

	return resource.Sample(samp, input.uv);
}