#include "Camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), m_MovementSpeed(SPEED)
{
	m_Position = position;
	m_Up = up;
	m_Yaw = yaw;
	m_Pitch = pitch;
	m_Right = glm::normalize(glm::cross(m_Front, m_Up));
	updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::updateCameraVectors()
{
	// calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = glm::normalize(front);
	// also re-calculate the Right and Up vector
	// m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp)); // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	// m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

void Camera::UpdatePosition(float deltaTime)
{
	// calculate the new looking direction according to mouse position
	// double x = InputHandler::m_MousePos.x;
	// double y = InputHandler::m_MousePos.y;

	// double lastX = InputHandler::m_MousePos.lastX;
	// double lastY = InputHandler::m_MousePos.lastY;

	// double xOffset = (x - lastX) * m_MouseSensitivity;
	// double yOffset = (lastY - y) * m_MouseSensitivity;

	// InputHandler::m_MousePos.lastX = x;
	// InputHandler::m_MousePos.lastY = y;

	// m_Yaw -= xOffset;
	// m_Pitch += yOffset;

	// if (m_Pitch > 89.0f)
	// 	m_Pitch = 89.0f;
	// if (m_Pitch < -89.0f)
	// 	m_Pitch = -89.0f;

	// glm::vec3 front;
	// front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	// front.y = sin(glm::radians(m_Pitch));
	// front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	// m_Front = glm::normalize(front);

	float velocity = m_MovementSpeed * deltaTime;
	if (InputHandler::keyIsDown('w'))
	{
		m_Position += m_Front * velocity;
	}
	if (InputHandler::keyIsDown('a'))
	{
		m_Position -= m_Right * velocity;
	}
	if (InputHandler::keyIsDown('s'))
	{
		m_Position -= m_Front * velocity;
	}
	if (InputHandler::keyIsDown('d'))
	{
		m_Position += m_Right * velocity;
	}
}
