#pragma once
#include "Texture.h"
#include "Engine.h"

class RendererGL;
class TextureGL : public Texture
{
	RendererGL* Renderer;
	uint32 TextureID;

public:
	const uint32 GetTextureID() const { return TextureID; }

	void SetTexture() {} // using IMAGE class (tbd)!
	void SetFiltering() {} // tbd

	void* GetBaseTexture() override final
	{
		return static_cast<TextureGL*>(this);
	}

	void ENABLETEX();

	TextureGL(RendererGL* renderer, uint32 textureID);
};