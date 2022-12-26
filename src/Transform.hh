#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Transform
{
public:
	Transform(glm::mat4& model, glm::mat4& rot, glm::mat4& tra);
	void translate(const glm::vec3& position);
	void rotate(float speed, const glm::vec3& direction);
private:
	glm::mat4& model;
	glm::mat4& rot;
	glm::mat4& tra;
};
