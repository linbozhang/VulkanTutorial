
struct Varyings
{
	float4 postionCS:SV_Position;
	half3 color:TEXCOORD0;
};
struct AppData
{
	uint vertexID:SV_VertexID;
};

Varyings Vertex(AppData input)
{
half2 positions[3]=
{
	half2(0,-0.5),
	half2(0.5,0.5),
	half2(-0.5,-0.5)
};
half3 colors[3] =
{
		half3(1, 0, 0),
		half3(0, 1, 0),
		half3(0, 0, 1)
};
	Varyings output = (Varyings)0;
	output.postionCS = float4(positions[input.vertexID], 0, 1);
	output.color=colors[input.vertexID];
	return output;
}

half4 Fragment(Varyings input):SV_Target
{
	return half4(input.color,1);
}