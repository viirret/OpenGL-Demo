#include "Material.hh"

#include <GL/glew.h>

Material::Material(const char* vertexShader, const char* fragmentShader)
	: shader(vertexShader, fragmentShader),
	color(glGetUniformLocation(shader.ID, "color")),
	mvp(glGetUniformLocation(shader.ID, "mvp"))
{
	glUseProgram(shader.ID);
}

const unsigned int& Material::getColor() const { return color; }

void Material::use() { glUseProgram(shader.ID); }
