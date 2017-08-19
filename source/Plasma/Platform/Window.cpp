#include "Window.h"

#ifdef PLATFORM_WINDOWS
#include "Platform/Windows/WindowWin32.h"
typedef WindowWin32 SystemWindow;

#elif PLATFORM_MACOS
#include "Platform/MacOS/WindowMacOS.h"
typedef WindowMacOS SystemWindow; // TODO: this is just an example
#endif

void Window::Update()
{
	if (platformWindow)
		platformWindow->Update();
}

Window::Window() : Window("Plasma", 1280, 720) {}
Window::Window(const char* title, int width, int height)
{
	platformWindow = new SystemWindow(title, width, height);
}
Window::~Window()
{
	delete platformWindow;
}