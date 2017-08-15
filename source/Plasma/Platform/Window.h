#pragma once

class PlatformWindow
{
public:

	virtual void Update() = 0;

	virtual void SetTitle() { return; }

	virtual void* GetWindowHandle() = 0;
};

class Window
{
	PlatformWindow* platformWindow;

public:
	void Update();

	void* GetWindowHandle() { return platformWindow->GetWindowHandle(); }

	Window();
	Window(const char* title, int width, int height);
	~Window();
};
