#include "Transform.hh"

Transform::Transform() : model(glm::mat4(1))
{
}

void Transform::translate(const glm::vec3& position)
{
	model = glm::translate(model, position);
}

void Transform::rotate(float speed, const glm::vec3& direction)
{
 	model = glm::rotate(model, speed, direction);
}

void Transform::scale(const glm::vec3& scale)
{
	model = glm::scale(model, scale);
}
