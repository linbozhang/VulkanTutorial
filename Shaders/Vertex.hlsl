
struct VertexOut
{
	float4 postionCS:SV_Position;
	min16float3 color:TEXCOORD0;
};
struct VertexInput
{
	uint vertexID:SV_VertexID;
};

VertexOut vs_main(VertexInput input)
{
	float2 positions[3] =
	{
		float2(0,-0.5),
		float2(0.5,0.5),
		float2(-0.5,0.5)
	};
	min16float3 colors[3] =
	{
			min16float3(1, 0, 0),
			min16float3(0, 1, 0),
			min16float3(0, 0, 1)
	};
	VertexOut output = (VertexOut)0;
	output.postionCS = float4(positions[input.vertexID], 0.5, 1);
	output.color = colors[input.vertexID];
	return output;
}

float4 ps_main(VertexOut input) :SV_Target0
{
	return float4(input.color,1);
}