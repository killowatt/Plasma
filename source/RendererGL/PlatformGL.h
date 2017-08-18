#pragma once
#include "Engine.h"
#include "GL/glew.h"


#include <string> // TODO: remove

class PlatformGL : private NonCopyable
{
private:
	static bool AnisotropicFilteringSupported;
	static float MaxAnisotropicLevel;

	static bool IsExtensionSupported(const char *extension) // TODO: borrowed, do self
	{
		const GLubyte *extensions = NULL;
		const GLubyte *start;
		GLubyte *where, *terminator;

		/* Extension names should not have spaces. */
		where = (GLubyte *)strchr(extension, ' ');
		if (where || *extension == '\0')
			return 0;

		extensions = glGetString(GL_EXTENSIONS);
		/* It takes a bit of care to be fool-proof about parsing the
		OpenGL extensions string. Don't be fooled by sub-strings,
		etc. */
		start = extensions;
		for (;;) 
		{
			where = (GLubyte *)strstr((const char *)start, extension);
			if (!where)
				break;
			terminator = where + strlen(extension);
			if (where == start || *(where - 1) == ' ')
				if (*terminator == ' ' || *terminator == '\0')
					return true;
			start = terminator;
		}
		return false;
	}

public:
	static void PopulateExtensions()
	{
		const GLubyte* extensions = nullptr;
		extensions = glGetString(GL_EXTENSIONS);

		// TODO: do this ourselves

		AnisotropicFilteringSupported =
			IsExtensionSupported("GL_EXT_texture_filter_anisotropic");

		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &MaxAnisotropicLevel);
	}

	static bool SupportsAnisotropicFiltering() { return AnisotropicFilteringSupported; }

	static float GetMaxAnisotropicLevel() { return MaxAnisotropicLevel; }
};