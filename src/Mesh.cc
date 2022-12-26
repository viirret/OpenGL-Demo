#include "Mesh.hh"

#include <iostream>

Mesh::Mesh() 
	: 	model(glm::mat4(1)),
		rot(glm::mat4(1)),
		tra(glm::mat4(1)),
		material("../shaders/vertex.vert", "../shaders/frag.frag"),
		transform(model, rot, tra)
{
	std::cout << "Mesh constuctor called" << std::endl;
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
	glUniformMatrix4fv(material.getmmID(), 1, GL_FALSE, &model[0][0]);
	glUniformMatrix4fv(material.getvmID(), 1, GL_FALSE, &camera.view[0][0]);
	glUniformMatrix4fv(material.getpmID(), 1, GL_FALSE, &camera.projection[0][0]);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
