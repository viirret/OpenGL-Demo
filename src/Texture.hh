#pragma once

#include <string>

struct Texture
{
	Texture(const std::string& path);
	Texture(){}
	std::string path;
	unsigned int texture;
};
