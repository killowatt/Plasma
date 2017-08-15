#pragma once

#include "Platform/Window.h"
#include "Engine.h"
#include <Windows.h>

class WindowWin32 : public PlatformWindow
{
private:
	HINSTANCE instance;
	HWND handle;

	static uint32 windowCount;

public:

	void Update();

	void Close();

	void* GetWindowHandle() { return handle; }

	WindowWin32(const char* title, int width, int height);
};