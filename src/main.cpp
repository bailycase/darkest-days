// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include "Renderer/Shader.hpp"
// #include "Renderer/VertexBuffer.hpp"
// #include "Renderer/IndexBuffer.hpp"
// #include "Renderer/VertexArray.hpp"
// #include "Renderer/VertexBufferLayout.hpp"
// #include "Renderer/Texture.hpp"
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <imgui.h>
// #include <imgui_impl_glfw.h>
// #include <imgui_impl_opengl3.h>

// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }

// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// int main()
// {
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     GLFWwindow *window = glfwCreateWindow(800, 600, "Darkest Days", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         return -1;
//     }

//     glfwMakeContextCurrent(window);

//     glfwSwapInterval(1);

//     // initialize glad
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     glViewport(0, 0, 800, 600);

//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     float vertices[] = {
//         100.0f, 100.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
//         200.0f, 100.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
//         200.0f, 200.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
//         100.0f, 200.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // top left
//     };

//     unsigned int indices[] = {
//         // note that we start from 0!
//         0, 1, 2, // first triangle
//         2, 3, 0  // second triangle
//     };

//     float texCoords[] = {0.0f,
//                          0.0f,
//                          1.0f,
//                          0.0f,
//                          0.5f,
//                          1.0f};

//     VertexArray VAO;
//     VertexBuffer vb(vertices, sizeof(vertices));
//     VertexBufferLayout layout;
//     layout.Push<float>(3);
//     layout.Push<float>(3);
//     layout.Push<float>(2);
//     VAO.AddBuffer(vb, layout);

//     IndexBuffer ib(indices, sizeof(indices));
//     Shader shader("res/shaders/basic.shader");
//     shader.Bind();

//     Texture texture("res/textures/container.jpg");
//     texture.bind();

//     // setup imgui
//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO &io = ImGui::GetIO();
//     ImGui_ImplGlfw_InitForOpenGL(window, true);
//     ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

//     ImGui::StyleColorsDark();

//     bool show_test_window = true;
//     bool wireFrameEnabled = false;
//     ImVec4 clear_color = ImColor(114, 144, 154);

//     glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
//     glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));

//     glm::vec3 translation(200, 200, 0);
//     // main loop
//     while (!glfwWindowShouldClose(window))
//     {

//         // handle input commands
//         processInput(window);

//         // handle translating
//         {
//             glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);

//             glm::mat4 mvp = proj * view * model;
//             shader.SetUniformMat4f("u_MVP", mvp);

//             if (wireFrameEnabled)
//             {
//                 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//             }
//             else
//             {
//                 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//             }

//             ImGui_ImplOpenGL3_NewFrame();
//             ImGui_ImplGlfw_NewFrame();
//             ImGui::NewFrame();
//         }

//         // render
//         glClear(GL_COLOR_BUFFER_BIT);
//         VAO.bind();
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

//         {
//             ImGui::Begin("Internal Testing Tool");
//             ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 960.0f);
//             ImGui::NewLine();
//             ImGui::Checkbox("Enable Wireframe", &wireFrameEnabled);
//             ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//             ImGui::End();
//             ImGui::Render();
//             ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//         }

//         // check and call events and swap the buffers
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplGlfw_Shutdown();
//     ImGui::DestroyContext();

//     glfwTerminate();
//     return 0;
// }

#include "Game.hpp"

int main()
{
    Game game;
    game.Run();
    return 0;
}