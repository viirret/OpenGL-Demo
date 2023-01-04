#pragma once

#include <string>

class Shader
{
public:
	// constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	// the program ID
	unsigned int ID;

private:
	std::string vertexCode;
	std::string fragmentCode;
	void checkCompileErrors(unsigned int shader, std::string type);
};

