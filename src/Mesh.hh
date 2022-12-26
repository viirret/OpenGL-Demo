#pragma once

#include "Material.hh"
#include "Transform.hh"
#include "Camera.hh"

#include <GL/glew.h>

class Mesh
{
public:
	Mesh();

	void render(Camera& camera);
	void translate(const glm::vec3& position);
	void rotate(float speed, const glm::vec3& direction);

protected:
	glm::mat4 model = glm::mat4(1);
	glm::mat4 rot = glm::mat4(1);
	glm::mat4 tra = glm::mat4(1);

	unsigned int vao;

	Material material;
	Transform transform;
};
