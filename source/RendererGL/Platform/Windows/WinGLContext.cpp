#include "WinGLContext.h"
#include "GL/glew.h"

void WinGLContext::MakeCurrent()
{

}
void WinGLContext::SwapBuffers()
{
	::SwapBuffers(DeviceContext);
}

void WinGLContext::Initialize(void* WindowHandle)
{

	PIXELFORMATDESCRIPTOR desiredPixelFormat =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		32,                        //Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	DeviceContext = GetDC((HWND)WindowHandle);

	int pixelFormat = ChoosePixelFormat(DeviceContext, &desiredPixelFormat);
	if (!pixelFormat || !SetPixelFormat(DeviceContext, pixelFormat, &desiredPixelFormat))
		return; // Failed to set pixel format for device context %.

	RenderingContext = wglCreateContext(DeviceContext);
	wglMakeCurrent(DeviceContext, RenderingContext); //debatable

	MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
}

WinGLContext::~WinGLContext()
{
	wglDeleteContext(RenderingContext);
}