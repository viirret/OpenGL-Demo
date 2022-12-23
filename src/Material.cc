#include "Material.hh"

#include <GL/glew.h>

Material::Material(const char* vertexShader, const char* fragmentShader)
	: shader(vertexShader, fragmentShader),

	mmID(glGetUniformLocation(shader.ID, "mm")),
	vmID(glGetUniformLocation(shader.ID, "vm")),
	pmID(glGetUniformLocation(shader.ID, "pm"))
{
	glUseProgram(shader.ID);
}

unsigned int Material::getmmID() const { return mmID; }
unsigned int Material::getvmID() const { return vmID; }
unsigned int Material::getpmID() const { return pmID; }
