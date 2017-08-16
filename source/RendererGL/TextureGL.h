#pragma once
#include "Texture.h"
#include "Engine.h"

class TextureGL : public Texture
{
	uint32 textureID;

public:

	void* GetBaseTexture() override final
	{
		return static_cast<TextureGL*>(this);
	}
};