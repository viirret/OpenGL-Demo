#include "Transform.hh"

Transform::Transform(glm::mat4& model, glm::mat4& rot, glm::mat4& tra)
	: model(model), rot(rot), tra(tra)
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
