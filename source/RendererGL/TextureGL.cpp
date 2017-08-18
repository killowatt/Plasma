#include "TextureGL.h"

#include "PlatformGL.h"

#include "GL/glew.h"

void TextureGL::SetFiltering(TextureFilter filter, float anisotropicLevel)
{
	glBindTexture(GL_TEXTURE_2D, TextureID);

	int32 MinFilter = 0, MagFilter = 0;
	switch (filter)
	{
	default:
	case TextureFilter::Nearest:
	case TextureFilter::AnisotropicNearest:
		MinFilter = GL_NEAREST_MIPMAP_NEAREST;
		MagFilter = GL_NEAREST;
		break;
	case TextureFilter::Bilinear:
		MinFilter = GL_LINEAR_MIPMAP_NEAREST;
		MagFilter = GL_LINEAR;
		break;
	case TextureFilter::Trilinear:
	case TextureFilter::AnisotropicLinear:
		MinFilter = GL_LINEAR_MIPMAP_LINEAR;
		MagFilter = GL_LINEAR;
		break;

	//case TextureFilter::AnisotropicNearest: // Not checking for support is fine;
	//	MinFilter = GL_NEAREST_MIPMAP_NEAREST; // Because it equates to NEAREST or Trilinear
	//	MagFilter = GL_NEAREST;
	//	break;
	//case TextureFilter::AnisotropicLinear:
	//	MinFilter = GL_LINEAR_MIPMAP_LINEAR;
	//	MagFilter = GL_LINEAR;
	//	break;
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MinFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MagFilter);

	if (anisotropicLevel && PlatformGL::SupportsAnisotropicFiltering())
	{
		float MaxAnisotropy =
			PlasmaMath::Min(anisotropicLevel, PlatformGL::GetMaxAnisotropicLevel());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, MaxAnisotropy);
	}
}

TextureGL::TextureGL(RendererGL* renderer, uint32 textureID)
{
	Renderer = renderer;
	TextureID = textureID;
}

void TextureGL::ENABLETEX()
{
	glBindTexture(GL_TEXTURE_2D, TextureID);
}
