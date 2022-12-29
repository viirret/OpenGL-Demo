#pragma once

#include "Mesh.hh"

#include <glm/glm.hpp>

#include <vector>

class Cube : public Mesh
{
public:
	// create cube with default color
	Cube();
	
	// create cube with color
	Cube(glm::vec3 color);

	void render(Camera& camera) override;

private:
	std::vector<float> createVertexBufferData();
	
	void create(std::vector<float>&& vertexBufferData);
};

