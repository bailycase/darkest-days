#include "InputHandler.hpp"

std::unordered_map<int, char> Keys{
    {87, 'w'},
    {65, 'a'},
    {83, 's'},
    {68, 'd'},
};

std::unordered_map<char, bool> InputHandler::m_PressedKeys;
MousePos InputHandler::m_MousePos;
bool InputHandler::m_InitialMouseEnter = true;

InputHandler::InputHandler(GLFWwindow *window)
{
	glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
			   { InputHandler::HandleKeyboardInput(key); });
	glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
				 { InputHandler::HandleMouseInput(x, y); });
}

void InputHandler::HandleMouseInput(double x, double y)
{
	if (m_InitialMouseEnter)
	{
		m_MousePos.lastX = x;
		m_MousePos.lastY = y;
		m_InitialMouseEnter = false;
	}

	m_MousePos.x = x;
	m_MousePos.y = y;
}

void InputHandler::HandleKeyboardInput(int key)
{
	auto mappedKey = Keys.find(key);
	if (mappedKey != Keys.end())
	{
		if (m_PressedKeys[mappedKey->second])
		{
			m_PressedKeys.insert_or_assign(mappedKey->second, false);
		}
		else
		{
			m_PressedKeys.insert_or_assign(mappedKey->second, true);
		}
	}
}

bool InputHandler::keyIsDown(char key)
{
	if (m_PressedKeys[key])
	{
		return true;
	}
	return false;
}

MousePos InputHandler::MousePosition()
{
	return m_MousePos;
}
