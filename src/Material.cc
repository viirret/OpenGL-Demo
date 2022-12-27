#include "Material.hh"

#include <GL/glew.h>

Material::Material(const char* vertexShader, const char* fragmentShader)
	: shader(vertexShader, fragmentShader),

	mmID(glGetUniformLocation(shader.ID, "mm")),
	vmID(glGetUniformLocation(shader.ID, "vm")),
	pmID(glGetUniformLocation(shader.ID, "pm")),
	color(glGetUniformLocation(shader.ID, "color"))
{
	glUseProgram(shader.ID);
}

const unsigned int& Material::getmmID() const { return mmID; }
const unsigned int& Material::getvmID() const { return vmID; }
const unsigned int& Material::getpmID() const { return pmID; }
const unsigned int& Material::getColor() const { return color; }
