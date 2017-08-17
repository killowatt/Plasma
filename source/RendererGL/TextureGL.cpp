#include "TextureGL.h"

#include "GL/glew.h"

TextureGL::TextureGL(RendererGL* renderer, uint32 textureID)
{
	Renderer = renderer;
	TextureID = textureID;
}

void TextureGL::ENABLETEX()
{
	glBindTexture(GL_TEXTURE_2D, TextureID);
}
