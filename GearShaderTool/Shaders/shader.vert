#version 450
#extension GL_ARB_separate_shader_objects : enable

layout (set = 1, binding = 0) uniform sampler2D samplerColorMap;
layout(binding = 0) uniform UniformBufferObject
{
	bool pan;
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragPosition;
layout(location = 1) out vec3 fragNormal;
layout(location = 2) out vec2 fragTexCoord;


out gl_PerVertex 
{
    vec4 gl_Position;
};

void main() 
{
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 1.0);
	fragPosition = gl_Position.xyz;
	mat3 normalMatrix = transpose(inverse(mat3(ubo.model)));
    fragNormal = normalMatrix * inNormal;
    fragTexCoord = inTexCoord;
}