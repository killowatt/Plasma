#pragma once
#include "Texture.h"

// TODO: remove
#include <iostream>

class Renderer
{
public:
	virtual void Initialize(void* windowHandle) // TODO: intake WINDOW class, not pointer idiot
	{
		std::cout << "Hello from interface!\n";
	}

	virtual Texture* CreateTexture() = 0;
};