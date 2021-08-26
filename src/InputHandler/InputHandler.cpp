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
char InputHandler::m_LastPressedKey = ' ';

InputHandler::InputHandler(GLFWwindow *window)
{
	glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
					   { InputHandler::HandleKeyboardInput(key, action); });
	// glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
	// 			 { InputHandler::HandleMouseInput(x, y); });
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

void InputHandler::HandleKeyboardInput(int key, int action)
{
	// 0 key release
	// 1 key press
	// 2 key hold

	std::cout << action << std::endl;

	auto mappedKey = Keys.find(key);

	if (mappedKey != Keys.end())
	{
		if (action == 0)
		{
			m_PressedKeys.insert_or_assign(mappedKey->second, false);
		}
		if (action == 1)
		{
			m_PressedKeys.insert_or_assign(mappedKey->second, true);
		}
	}

	// if (mappedKey != Keys.end())
	// {
	// 	if (!m_PressedKeys[mappedKey->second])
	// 	{
	// 		m_PressedKeys.insert_or_assign(mappedKey->second, true);
	// 	}
	// 	else
	// 	{
	// 		m_PressedKeys.insert_or_assign(mappedKey->second, false);
	// 	}
	// }
}

bool InputHandler::keyIsDown(char key)
{
	if (m_PressedKeys[key])
	{
		return true;
	}
	return false;
}

char InputHandler::GetCurrentPressedKey()
{
	for (auto it = m_PressedKeys.begin(); it != m_PressedKeys.end(); ++it)
	{
		if (it->second == true)
		{
			return it->first;
		}
	}
	return ' ';
}

MousePos InputHandler::MousePosition()
{
	return m_MousePos;
}
