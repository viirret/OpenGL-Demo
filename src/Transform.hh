#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Transform
{
public:
	Transform();
	virtual void translate(const glm::vec3& position);
	virtual void rotate(float speed, const glm::vec3& direction);
	const glm::mat4& getModel() { return model; }
protected:
	glm::mat4 model;
};
