E:\workprogram\VulkanSDK1_3_216_0\Bin\dxc.exe -spirv -T vs_5_0 -E vs_main .\Vertex.hlsl -Fo .\vert.spv
E:\workprogram\VulkanSDK1_3_216_0\Bin\dxc.exe -spirv -T ps_5_0 -E ps_main .\Vertex.hlsl -Fo .\frag.spv
copy .\vert.spv ..\x64\Debug\Shaders\vert.spv
copy .\frag.spv ..\x64\Debug\Shaders\frag.spv
pause