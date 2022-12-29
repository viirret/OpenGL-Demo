#include "Cube.hh"

#include <GL/glew.h>
	
// create cube with color
Cube::Cube() : Mesh(glm::vec3(1.0f, 1.0f, 1.0f))
{
	create(createVertexBufferData());
}

Cube::Cube(glm::vec3 color) : Mesh(color)
{
	create(createVertexBufferData());
}

void Cube::create(std::vector<float>&& vertexBufferData)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(float), &vertexBufferData[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Cube::render(Camera& camera)
{
	glm::mat4 mvp = camera.getProjection() * camera.getView() * transform.getModel();

	material.use();

	glUniformMatrix4fv(material.getMvp(), 1, GL_FALSE, &mvp[0][0]);
	
	// set color
	glUniform3f(material.getColor(), color.x, color.y, color.z);

	// bind the VAO
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	// Unbind the VAO
	glBindVertexArray(0);

	glUseProgram(0);
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

