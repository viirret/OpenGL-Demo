#include "Camera.hh"

#include <SDL2/SDL.h>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	: front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), zoom(ZOOM),
	position(position), worldUp(up), pitch(PITCH), yaw(YAW), view(glm::lookAt(position, position + front, up)),
	projection(glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f))
{
	updateCameraVectors();
}

void Camera::translate(const glm::vec3& position)
{
	this->position += position;
	updateCameraVectors();
	view = glm::translate(view, position);
}

void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch -= yoffset;

	// update Front, Right and Up Vectors using the updated Euler angles
	updateCameraVectors();
}

void Camera::updateCameraVectors()
{
	// calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	// also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(front, worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));

	view = glm::lookAt(position, position + front, up);
}


