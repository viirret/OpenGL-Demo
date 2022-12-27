#include "Camera.hh"

Camera::Camera(glm::mat4 view, glm::mat4 projection)
	: view(view), projection(projection)
{
}

void Camera::setView(glm::mat4& view)
{
	this->view = view;
}
