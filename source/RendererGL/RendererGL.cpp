#include "RendererGL.h"

#ifdef PLATFORM_WINDOWS
#include "Platform/Windows/WinGLContext.h"   // TODO: move these preprocessor to context files?
typedef WinGLContext PlatformContext;

#elif PLATFORM_MACOS
#include "Platform/MacOS/MacOSContext.h"
typedef MacOSContext PlatformContext;
#endif

#include "GL/glew.h"

void RendererGL::Initialize(void* windowHandle)
{
	context = new PlatformContext();
	context->Initialize(windowHandle);

	GLenum error = glewInit();
	if (GLEW_OK != error)
		return;


	// temp 
	std::cout << "Hello from GL\n";
	Renderer::Initialize(windowHandle);
}

RendererGL::~RendererGL()
{
	if (context)
		delete context;
}