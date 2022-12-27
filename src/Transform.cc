#include "Transform.hh"

Transform::Transform()
	: model(glm::mat4(1)), rot(glm::mat4(1)), tra(glm::mat4(1))
{
}

void Transform::translate(const glm::vec3& position)
{
	model = glm::translate(model, position);
}

void Transform::rotate(float speed, const glm::vec3& direction)
{
 	rot = glm::rotate(rot, speed, direction);
	model = tra * rot;
}
