#include "Cube.hh"

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Debug.hh"
	
// create cube with texture
Cube::Cube(const std::string& texturePath) : Mesh(glm::vec3(1.0f, 1.0f, 1.0f), texturePath)
{
	create(createVertexBufferData(), createUvData());
}

// create cube with colorized texture
Cube::Cube(const std::string& texturePath, const glm::vec3& cubeColor) : Mesh(cubeColor, texturePath)
{
	create(createVertexBufferData(), createUvData());
}

void Cube::create(std::vector<float>&& vertexBufferData, std::vector<float>&& uvData)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// vertexData
	unsigned int vertexVBO;
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(float), &vertexBufferData[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord data
	unsigned int uvVBO;
	glGenBuffers(1, &uvVBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glBufferData(GL_ARRAY_BUFFER, uvData.size() * sizeof(float), &uvData[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);

	// Unbind the VAO and VBOs.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Cube::render(Camera& camera)
{
	Mesh::renderOverrider(camera, [this]()
	{
		glDrawArrays(GL_TRIANGLES, 0, 36);
	});
}

std::vector<float> Cube::createVertexBufferData()
{ 
	std::vector<float> vertexData
	{
		-1.0f, -1.0f, -1.0f,  
		 1.0f, -1.0f, -1.0f,  
		 1.0f,  1.0f, -1.0f,  
		 1.0f,  1.0f, -1.0f,  
		-1.0f,  1.0f, -1.0f,  
		-1.0f, -1.0f, -1.0f,  

		-1.0f, -1.0f,  1.0f,  
		 1.0f, -1.0f,  1.0f,  
		 1.0f,  1.0f,  1.0f,  
		 1.0f,  1.0f,  1.0f,  
		-1.0f,  1.0f,  1.0f,  
		-1.0f, -1.0f,  1.0f,  

		-1.0f,  1.0f,  1.0f,  
		-1.0f,  1.0f, -1.0f,  
		-1.0f, -1.0f, -1.0f,  
		-1.0f, -1.0f, -1.0f,  
		-1.0f, -1.0f,  1.0f,  
		-1.0f,  1.0f,  1.0f,  

		 1.0f,  1.0f,  1.0f,  
		 1.0f,  1.0f, -1.0f,  
		 1.0f, -1.0f, -1.0f,  
		 1.0f, -1.0f, -1.0f,  
		 1.0f, -1.0f,  1.0f,  
		 1.0f,  1.0f,  1.0f,  

		-1.0f, -1.0f, -1.0f,  
		 1.0f, -1.0f, -1.0f,  
		 1.0f, -1.0f,  1.0f,  
		 1.0f, -1.0f,  1.0f,  
		-1.0f, -1.0f,  1.0f,  
		-1.0f, -1.0f, -1.0f,  

		-1.0f,  1.0f, -1.0f,  
		 1.0f,  1.0f, -1.0f,  
		 1.0f,  1.0f,  1.0f,  
		 1.0f,  1.0f,  1.0f,  
		-1.0f,  1.0f,  1.0f,  
		-1.0f,  1.0f, -1.0f,  
	};
	
	return vertexData;
}

std::vector<float> Cube::createUvData()
{
	std::vector<float> data
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	return data;
}

