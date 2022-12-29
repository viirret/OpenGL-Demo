#pragma once

#include "Material.hh"
#include "Transform.hh"
#include "ObjLoader.hh"
#include "Camera.hh"

#include <GL/glew.h>

class Mesh
{
public:
	Mesh(const glm::vec3& color);
	Mesh(const std::string& path);
	Mesh(const std::string& path, const glm::vec3& color);

	virtual void render(Camera& camera);
	void translate(const glm::vec3& position);
	void rotate(float speed, const glm::vec3& direction);

protected:
	void createObject();
	glm::vec3 color;
	unsigned int vao;

	Material material;
	Transform transform;
	ObjLoader objLoader;
};
