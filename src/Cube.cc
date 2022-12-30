#include "Cube.hh"

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Debug.hh"
	
// create cube with color
Cube::Cube(const std::string& texturePath) : Mesh(glm::vec3(1.0f, 1.0f, 1.0f), texturePath)
{
	create(createVertexBufferData(), createUvData());
}

Cube::Cube(const std::string& texturePath, const glm::vec3& cubeColor) : Mesh(cubeColor, texturePath)
{
	create(createVertexBufferData(), createUvData());
}

void Cube::create(std::vector<float>&& vertexBufferData, std::vector<float>&& uvData)
{
	std::vector<float> normalBufferData;

	// vertices of the cube.
	std::vector<glm::vec3> vertices =
	{
		glm::vec3(-1.0f, -1.0f, -1.0f), // 0
		glm::vec3(-1.0f, -1.0f,  1.0f), // 1
		glm::vec3(-1.0f,  1.0f, -1.0f), // 2
		glm::vec3(-1.0f,  1.0f,  1.0f), // 3
		glm::vec3( 1.0f, -1.0f, -1.0f), // 4
		glm::vec3( 1.0f, -1.0f,  1.0f), // 5
		glm::vec3( 1.0f,  1.0f, -1.0f), // 6
		glm::vec3( 1.0f,  1.0f,  1.0f)  // 7
	};

	// indices of the triangles.
	std::vector<unsigned int> indices =
	{
		0, 1, 2, 2, 1, 3,
		4, 5, 6, 6, 5, 7,
		4, 0, 6, 6, 0, 2,
		1, 5, 3, 3, 5, 7,
		4, 5, 0, 0, 5, 1,
		2, 3, 6, 6, 3, 7
	};

	// calculate vertex normals.
	std::vector<glm::vec3> normals(vertices.size(), glm::vec3(0.0f, 0.0f, 0.0f));
	for (unsigned int i = 0; i < indices.size(); i += 3)
	{
		const glm::vec3& v1 = vertices[indices[i]];
		const glm::vec3& v2 = vertices[indices[i+1]];
		const glm::vec3& v3 = vertices[indices[i+2]];

		glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));

		normals[indices[i]] += normal;
		normals[indices[i+1]] += normal;
		normals[indices[i+2]] += normal;
	}

	for (unsigned int i = 0; i < normals.size(); i++)
	{
		normals[i] = glm::normalize(normals[i]);

		// append the normal data to the normal buffer data.
		normalBufferData.push_back(normals[i].x);
		normalBufferData.push_back(normals[i].y);
		normalBufferData.push_back(normals[i].z);
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vertexVBO;
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(float), &vertexBufferData[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int uvVBO;
	glGenBuffers(1, &uvVBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glBufferData(GL_ARRAY_BUFFER, uvData.size() * sizeof(float), &uvData[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);

	unsigned int normalVBO;
	glGenBuffers(1, &normalVBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
	glBufferData(GL_ARRAY_BUFFER, normalBufferData.size() * sizeof(float), &normalBufferData[0], GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Cube::render(Camera& camera)
{
	glm::mat4 mvp = camera.getProjection() * camera.getView() * transform.getModel();

	material.use();

	if(tex.path != "")
	{
		glBindTexture(GL_TEXTURE_2D, tex.texture);
	}
	else
	{
		DBG_LOG("NO PATH IN CUBE");
	}

	// bind the VAO
	glBindVertexArray(vao);

	glUniformMatrix4fv(material.getMvp(), 1, GL_FALSE, &mvp[0][0]);
	
	// set color
	glUniform4f(material.getColor(), color.x, color.y, color.z, 0.0f);

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

std::vector<float> Cube::createUvData()
{
	std::vector<float> data
	{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,

		0.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,

		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,

		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f
	};

	return data;
}

