#version 330 core

out vec4 FragColor;

in vec2 uv;

uniform sampler2D texture1;
uniform vec4 color;

void main()
{
	FragColor = texture(texture1, uv) * color;
}
