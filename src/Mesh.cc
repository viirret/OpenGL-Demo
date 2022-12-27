#include "Mesh.hh"

#include <iostream>

Mesh::Mesh()
	: 	material("../shaders/vertex.vert", "../shaders/frag.frag"),
		transform(),
		objLoader()
{
}

Mesh::Mesh(const std::string& path)
	: 	material("../shaders/vertex.vert", "../shaders/frag.frag"),
		transform(),
		objLoader(path)
{
	// get the vertices, normals, texture coordinates, and indices from the OBJ file.
	const std::vector<glm::vec3>& vertices = objLoader.getVertices();
	const std::vector<glm::vec3>& normals = objLoader.getNormals();
	const std::vector<glm::vec2>& uvs = objLoader.getUVs();
	const std::vector<unsigned int>& indices = objLoader.getIndices();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vertexVBO;
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	unsigned int normalVBO;
	glGenBuffers(1, &normalVBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);

	unsigned int uvVBO;
	glGenBuffers(1, &uvVBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), uvs.data(), GL_STATIC_DRAW);

	// Generate an EBO and bind it.
	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Copy the indices to the EBO.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	// Unbind the VAO and VBOs.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::translate(const glm::vec3& position)
{
	transform.translate(position);
}

void Mesh::rotate(float speed, const glm::vec3& direction)
{
	transform.rotate(speed, direction);
}

void Mesh::render(Camera& camera)
{
	// Bind the VAO
	glBindVertexArray(vao);

	glUseProgram(material.getProgram());

	glUniformMatrix4fv(material.getmmID(), 1, GL_FALSE, &transform.getModel()[0][0]);
	glUniformMatrix4fv(material.getvmID(), 1, GL_FALSE, &camera.view[0][0]);
	glUniformMatrix4fv(material.getpmID(), 1, GL_FALSE, &camera.projection[0][0]);
	glUniform3f(material.getColor(), 0.0f, 1.0f, 0.0f);

	// Draw the mesh using the indices in the EBO
	glDrawElements(GL_TRIANGLES, objLoader.getIndices().size(), GL_UNSIGNED_INT, nullptr);

	// Unbind the VAO
	glBindVertexArray(0);

	glUseProgram(0);
}
