#include "RendererGL.h"

#ifdef PLATFORM_WINDOWS
#include "Platform/Windows/WinGLContext.h"   // TODO: move these preprocessor to context files?
typedef WinGLContext PlatformContext;

#elif PLATFORM_MACOS
#include "Platform/MacOS/MacOSContext.h"
typedef MacOSContext PlatformContext;
#endif

#include "TextureGL.h"
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

Texture* RendererGL::CreateTexture()
{
	uint32 textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Empty Texture
	GLubyte image[] = {
		0, 0, 0, 255,
		255, 0, 255, 255,
		255, 0, 255, 255,  
		0, 0, 0, 255
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image); // TODO:v

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // TODO: use set in tex
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	TextureGL* texture = new TextureGL(this, textureID);
	return texture;
}

RendererGL::~RendererGL()
{
	if (context)
		delete context;
}