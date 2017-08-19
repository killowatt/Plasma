
#include "VK/vulkan/vulkan.h"

#include <iostream>
#include <vector>

void GetRequiredExtensions(char** extensions) // FOR PLATFORM!
{
	// not final code obv
#ifdef PLATFORM_WINDOWS
	extensions[0] = "VK_KHR_surface";
	extensions[1] = "VK_KHR_win32_surface";
#elif PLATFORM_MACOS
	extensions[0] = "VK_KHR_surface";
	extensions[1] = "VK_MVK_macos_surface";
#endif
}

class VulkanTest
{
public:

	VkInstance instance;

	void Initialize()
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "PlasmaVulkan";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Plasma"; // ?
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		// createinfo
		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		const unsigned int extCount = 2;
		char** extensionss = new char *[extCount]; // required extensions
		GetRequiredExtensions(extensionss);

		// Extensions
		createInfo.enabledExtensionCount = extCount;
		createInfo.ppEnabledExtensionNames = extensionss;

		createInfo.enabledLayerCount = 0;

		
		// RESULT
		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
		std::cout << "CreateInstancerResult " << result << std::endl;

		if (result != VK_SUCCESS)
		{
			std::cout << "Vulkan failed to init";
			std::getchar();
		}



		// EXTENSION LISTING, NOT FUNCTIONALITY
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> extensions(extensionCount);

		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

		std::cout << "available extensions:" << std::endl;

		for (const auto& extension : extensions) {
			std::cout << "\t" << extension.extensionName << std::endl;
		}
		// END



	}

	void Destroy()
	{
		vkDestroyInstance(instance, nullptr);
	}

	VulkanTest()
	{

	}
};