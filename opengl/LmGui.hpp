#pragma once
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Lmgui
{
private:
public:
	static void Init(GLFWwindow *window);
	static void RenderImgui();
};