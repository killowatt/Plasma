#pragma once
#include "Platform/Context.h"
#include <Windows.h>

class WinGLContext : public Context
{
public:
	HWND WindowHandle;
	HDC DeviceContext;
	HGLRC RenderingContext;

	void MakeCurrent();
	void SwapBuffers();

	void Initialize(void* WindowHandle);

	WinGLContext() = default;
	~WinGLContext();
};