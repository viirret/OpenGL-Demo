#pragma once

#include "Material.hh"
#include "Transform.hh"
#include "ObjLoader.hh"
#include "Camera.hh"

#include <GL/glew.h>

class Mesh
{
public:
	Mesh();
	Mesh(const std::string& path);

	virtual void render(Camera& camera);
	void translate(const glm::vec3& position);
	void rotate(float speed, const glm::vec3& direction);

protected:
	unsigned int vao;

	Material material;
	Transform transform;
	ObjLoader objLoader;
};
