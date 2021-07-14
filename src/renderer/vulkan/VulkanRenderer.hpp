#pragma once
#include <vulkan.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <optional>

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};
class VulkanRenderer
{
public:
	VulkanRenderer();
	void initVulkan(GLFWwindow *window);
	void createVulkanInstance();
	void Cleanup();

private:
	VkInstance m_Instance;
	VkDevice m_LogicalDevice;
	VkPhysicalDevice m_PhysicalDevice;
	VkSurfaceKHR m_WindowSurface;
	VkQueue m_GraphicsQueue;
	VkQueue m_PresentQueue;
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	bool checkValidationLayerSupport();
	void getPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void createLogicalDevice();
	void createWindowSurface(GLFWwindow *window);
};