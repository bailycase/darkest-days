#pragma once
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "InputHandler/InputHandler.hpp"
#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Lmgui
{
private:
public:
	void Init(GLFWwindow *window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO &io = ImGui::GetIO();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
		ImGui::StyleColorsDark();
	};
	void RenderImgui(Coordinator *coordinator)
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
		// Systems List
		if (ImGui::BeginListBox("ECS Systems"))
		{
			for (const auto &system : coordinator->GetAllSystems())
			{
				std::cout << system.first << std::endl;
				ImGui::Selectable(system.first);
			};
			ImGui::EndListBox();
		}
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	};
};