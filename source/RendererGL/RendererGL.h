#pragma once

#include "Renderer.h"
#include "Platform/Context.h"

class RendererGL : public Renderer
{
public: // TEMP
	Context* context;

public:
	void Initialize(void* windowHandle);

	Texture* CreateTexture();

	~RendererGL();
};