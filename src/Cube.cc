#include "Cube.hh"

#include <GL/glew.h>
	
Cube::Cube() : Mesh()
{
	auto data = createVertexBufferData();
	create(data, rainbowColorBufferData);
}

// create cube with color
Cube::Cube(float color) : Mesh()
{
	auto vertexData = createVertexBufferData();

	std::vector<float> colorData;

	for(int i = 0; i < 109; i++)
		colorData.push_back(color);

	create(vertexData, colorData);
}

std::vector<float> Cube::createVertexBufferData()
{ 
	std::vector<float> vertexData
	{
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,

		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,

		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
	
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,

		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,

		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,

		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,

		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f
	};
	
	return vertexData;
}

void Cube::create(std::vector<float>& vertexBufferData)
{
	create(vertexBufferData, rainbowColorBufferData);
}	

void Cube::create(std::vector<float>& vertexBufferData, std::vector<float>& colorBufferData)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(std::vector<float>), &vertexBufferData[0], GL_STATIC_DRAW);

	unsigned int vcb;
	glGenBuffers(1, &vcb);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);

	glBufferData(GL_ARRAY_BUFFER, colorBufferData.size() * sizeof(std::vector<float>), &colorBufferData[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

