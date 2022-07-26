
struct VertexOut
{
	float4 postionCS:SV_Position;
	min16float3 color:TEXCOORD0;
};
struct VertexInput
{
	//uint vertexID:SV_VertexID;
	[[vk::location(0)]]float2 inPosition:Position;
	[[vk::location(1)]]float3 inColor:Color;
};
[[vk::binding(0, 0)]] cbuffer UniformBufferObject:register(b0)
{
	float4x4 model;
	float4x4 view;
	float4x4 proj;
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
	output.postionCS = mul(proj,mul(view,mul(model,float4(input.inPosition, 0.5, 1)))); //float4(input.inPosition.xy, 0, 1);// float4(positions[input.vertexID], 0.5, 1);
	output.color = min16float3(input.inColor);// colors[input.vertexID];
	return output;
}

float4 ps_main(VertexOut input) :SV_Target0
{
	return float4(input.color,1);
}