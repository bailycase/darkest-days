#include "LmGui.hpp"
#include "InputHandler/InputHandler.hpp"
#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

// static struct WindowSize
// {
// 	static int *x, *y;
// };

void Lmgui::Init(GLFWwindow *window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	// glfwGetWindowSize(window, WindowSize::x, WindowSize::y);
	// io.DisplaySize = ImVec2(Cast<float>(windowSize.x), Cast<float>(windowSize.y));
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

	ImGui::StyleColorsDark();
}

void Lmgui::RenderImgui()
{

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGuiIO &io = ImGui::GetIO();
	ImGui::Begin("Internal Testing Tool");
	//     ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 960.0f);
	ImGui::NewLine();
	//     ImGui::Checkbox("Enable Wireframe", &wireFrameEnabled);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::NewLine();
	ImGui::Text("Current pressed key: %c", InputHandler::GetCurrentPressedKey());
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
