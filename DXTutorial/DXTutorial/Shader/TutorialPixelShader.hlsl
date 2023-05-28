Texture2D resource : register(t0); //텍스처를 gpu 레지스터에 바인딩
SamplerState samp : register(s0);  //샘플러를 바인딩
//바인딩 : 어떤 자원을 특정 위치에 연결.
//gpu가 사용할 자원을 명시적으로 지정해 셰이더나 파이프라인에 연결하는 과정

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	if (input.uv.x == -1 && input.uv.y == -1)
		return input.color;

	float2 resultUV;
	resultUV.x = input.uv.x;
	resultUV.y = input.uv.y;

	return resource.Sample(samp, resultUV);
}