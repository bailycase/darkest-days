#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <InputHandler/InputHandler.hpp>

enum CameraMovement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SENSITIVITY = 0.01f;
const float ZOOM = 45.0f;
const float SPEED = 2.5f;

class Camera
{
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
	void ProcessKeyboard(CameraMovement direction, float deltaTime);
	void UpdatePosition(float deltaTime);
	glm::mat4 getViewMatrix();
	glm::vec3 m_Position;
	// glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
	// glm::vec3 m_Up = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
	glm::vec3 m_WorldUp;
	// euler angles
	// double m_Yaw = -90.0f;
	// double m_Pitch = 0.0f;
	double m_Yaw;
	double m_Pitch;
	// camera options
	float m_MovementSpeed;
	// float m_MovementSpeed = 10.0f;
	// float m_MouseSensitivity = 0.05f;
	float m_Zoom = ZOOM;
	glm::vec3 m_Direction;

private:
	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ViewProjectionMatrix;
	void updateCameraVectors();
};