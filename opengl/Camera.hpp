#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW = -90.0f;
const float PITCH = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 getViewMatrix();
	glm::vec3 m_Position;
	glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 m_Right;
	glm::vec3 m_WorldUp;
	// euler angles
	float m_Yaw = YAW;
	float m_Pitch = PITCH;
	// camera options
	float m_MovementSpeed;
	float m_MouseSensitivity = SENSITIVITY;
	float m_Zoom = ZOOM;
	void ProcessKeyboard(CameraMovement direction, float deltaTime);

private:
	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ViewProjectionMatrix;
	void updateCameraVectors();
};