#pragma once;
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <GLFW/glfw3.h>

struct MousePos
{
	double x;
	double y;
	double lastX;
	double lastY;
};

class InputHandler
{
private:
	static std::unordered_map<char, bool> m_PressedKeys;
	static bool m_InitialMouseEnter;

public:
	enum EventTypes;
	InputHandler(GLFWwindow *window);
	static void HandleMouseInput(double x, double y);
	static void HandleKeyboardInput(int key);
	void init(GLFWwindow *window);
	static bool keyIsDown(char key);
	static MousePos MousePosition();
	static MousePos m_MousePos;
};