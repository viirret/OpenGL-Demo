#pragma once

#include "Shader.hh"

class Material
{
public:
	Material(const char* vertexShader, const char* fragmentShader);
	const unsigned int& getProgram() { return shader.ID; }
	const unsigned int& getMvp() { return mvp; } 
	const unsigned int& getColor() const;

	void use();

private:
	Shader shader;
	unsigned int mvp;
	unsigned int color;
};
