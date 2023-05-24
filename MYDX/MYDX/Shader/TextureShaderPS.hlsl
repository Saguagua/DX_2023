Texture2D resource : register(t0); //GPU�� �������� -> �������, t0��° ���Կ� ����
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