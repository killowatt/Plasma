#pragma once

class Context
{
public:
	virtual void MakeCurrent() = 0;
	virtual void SwapBuffers() = 0;

	virtual void Initialize(void* WindowHandle) = 0;
};
