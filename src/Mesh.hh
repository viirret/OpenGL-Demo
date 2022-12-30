#pragma once

#include "Material.hh"
#include "Transform.hh"
#include "ObjLoader.hh"
#include "Camera.hh"
#include "Texture.hh"

#include <GL/glew.h>

class Mesh
{
public:
	Mesh(const glm::vec3& color, const std::string& texturePath);
	Mesh(const std::string& texturePath, const std::string& objPath);
	Mesh(const glm::vec3& color, const std::string& texturePath, const std::string& objPath);

	virtual void render(Camera& camera);
	void translate(const glm::vec3& position);
	void rotate(float speed, const glm::vec3& direction);
	void scale(const glm::vec3& scale);

protected:
	unsigned int vao;
	unsigned int texture;
	glm::vec3 color;

	Material material;
	Transform transform;
	ObjLoader objLoader;
	Texture tex;

	// get the vertices, normals, texture coordinates, and indices from the OBJ file.
	const std::vector<glm::vec3>& vertices = objLoader.getVertices();
	const std::vector<glm::vec3>& normals = objLoader.getNormals();
	const std::vector<glm::vec2>& uvs = objLoader.getUVs();
	const std::vector<unsigned int>& indices = objLoader.getIndices();

private:
	void createObject();
};
