#pragma once

#include "Shader.hh"

class Material
{
public:
	Material(const char* vertexShader, const char* fragmentShader);
	unsigned int getmmID() const;
	unsigned int getvmID() const;
	unsigned int getpmID() const;

private:
	Shader shader;
	unsigned int mmID;
	unsigned int vmID;
	unsigned int pmID;
};
