#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <map>
#include <optional>
#include <set>
#include <algorithm>
#include <fstream>

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;
	bool isComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};
struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};
class HelloTriangleAppliaction
{
public:
	void run();
private:
	GLFWwindow* window = nullptr;
	VkInstance instance = nullptr;
	VkDebugUtilsMessengerEXT debugMessenger = nullptr;
	VkSurfaceKHR surface;
	
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice logicalDevice = nullptr;
	
	VkQueue graphicsQueue = nullptr;
	VkQueue presentQueue = nullptr;
	
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	
	VkRenderPass renderPass;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;
	
	VkCommandPool commandPool;
	std::vector<VkCommandBuffer> commandBuffers;
	std::vector< VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	std::vector<VkFence> imagesInFlights;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	size_t currentFrame = 0;
	bool framebufferResized = false;


	void initWindow();
	void initVulkan();
	void mainLoop();
	void drawFrame();
	void cleanup();
	void createCommandBuffers();
	void createCommandPool();
	void createFramebuffers();
	void createInstance();
	void createVertexBuffer();
	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	bool checkValidationLayerSupport();
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	VkShaderModule createShaderModule(const std::vector<char>& code);
	void createRenderPass();
	void createGraphicsPipeline();
	std::vector<const char*> getRequiredExtensions();
	void createSwapChain();
	void createImageViews();
	void createSurface();
	void createLogicalDevice();
	void createSyncObjects();
	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	void recreateSwapChain();
	void cleanupSwapChain();
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice device);
	void pickPhysicalDevice();
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	bool isDeviceSuitable(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	int rateDeviceSuitability(VkPhysicalDevice device);
	void setupDebugMessenger();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
	{
		if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
		{
			std::cerr << "validation layer:" << pCallbackData->pMessage << std::endl;
		}

		return VK_FALSE;
	}

	static void framebufferResizeCallback(GLFWwindow* window, int widht, int height);
};
