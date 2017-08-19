
#include "VK/vulkan/vulkan.h"

#include <iostream>

int main()
{
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::cout << extensionCount << " extensions supported" << std::endl;
	std::getchar();

	return 0;
}