// Symentic Name
// SV : SystemValue
// x,y,z,0 or 1


struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float uv : UV;
};

VertexOutput VS(VertexInput input)
{
	VertexOutput result;
	result.pos = input.pos;
	result.color = input.color;
	result.uv = input.uv;
	return result;
}