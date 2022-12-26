#pragma once

#include "Shader.hh"

class Material
{
public:
	Material(const char* vertexShader, const char* fragmentShader);
	const unsigned int& getmmID() const;
	const unsigned int& getvmID() const;
	const unsigned int& getpmID() const;

private:
	Shader shader;
	unsigned int mmID;
	unsigned int vmID;
	unsigned int pmID;
};
