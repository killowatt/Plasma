#pragma once
#include "Engine.h"

class Texture : public NonCopyable
{
public:

	virtual void* GetBaseTexture() = 0;

};