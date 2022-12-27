#version 330 core

layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec2 vertexUV;
layout(location=2) in vec2 vertexNormal;

uniform mat4 mm;
uniform mat4 vm;
uniform mat4 pm;

uniform vec3 color;

out vec3 fragmentColor;
out vec2 uv;

void main()
{
	gl_Position = pm * vm * mm * vec4(vertexPosition, 1);
	fragmentColor = color;
	uv = vertexUV;
}
