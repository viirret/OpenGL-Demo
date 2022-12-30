#include "Texture.hh"

#include "Debug.hh"

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"

Texture::Texture(const std::string& path)
{
	this->path = path;

	// Generate texture object
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load image data from file using stb_image
	int width, height, numComponents;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &numComponents, 0);

	if(data)
	{
		// Upload image data to texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		DBG_LOG("FAILED TO CREATE TEXTURE: %s", path.c_str());
	}

	// Free image data
	stbi_image_free(data);
}
