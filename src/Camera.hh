#pragma once

#include <glm/glm.hpp>

struct Camera
{
	Camera(glm::mat4 view, glm::mat4 projection);
	glm::mat4 view;
	glm::mat4 projection;
	void setView(glm::mat4& view);
};