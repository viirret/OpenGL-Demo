#version 330 core

layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec2 vertexUV;
layout(location=2) in vec2 vertexNormal;

uniform mat4 mvp;

out vec2 uv;

void main()
{
	gl_Position = mvp * vec4(vertexPosition, 1);
	uv = vertexUV;
}
