#pragma once
#include "Engine.h"

enum class TextureFilter
{
	Nearest,
	Bilinear,
	Trilinear,
	AnisotropicNearest,
	AnisotropicLinear
};
enum class Anisotropic : int32
{
	// TODO: ?
};
class Texture : public NonCopyable
{
public:

	virtual void* GetBaseTexture() = 0;

	virtual void ENABLETEX() {} // TODO: temporary!

	virtual void SetFiltering(TextureFilter filter, float anisotropicLevel) {}

	Texture() {}
};