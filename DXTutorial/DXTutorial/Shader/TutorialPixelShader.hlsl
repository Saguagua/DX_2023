Texture2D resource : register(t0); //�ؽ�ó�� gpu �������Ϳ� ���ε�
SamplerState samp : register(s0);  //���÷��� ���ε�
//���ε� : � �ڿ��� Ư�� ��ġ�� ����.
//gpu�� ����� �ڿ��� ��������� ������ ���̴��� ���������ο� �����ϴ� ����

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