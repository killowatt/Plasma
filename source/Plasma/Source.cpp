#include <iostream>

#include "Platform/Window.h"

#include "RendererGL.h"
#include "GL/glew.h"

float rt = 0.0f;

Texture* texd;

void Update()
{
}
void Render()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	glRotatef(rt, 0, 0, 1);
	glRotatef(rt, 1, 0, 0);
	glScalef(0.5f, 0.5f, 0.5f);
	rt += 0.5f;


	texd->ENABLETEX();

	glBegin(GL_TRIANGLE_STRIP);

	float rp = 4;

	glTexCoord2f(0.0, 0.0);
	glVertex2f(-1.0, -1.0);

	glTexCoord2f(rp, 0.0);
	glVertex2f(1.0, -1.0);

	glTexCoord2f(0.0, rp);
	glVertex2f(-1.0, 1.0);

	glTexCoord2f(rp, rp);
	glVertex2f(1.0, 1.0);

	glEnd();

}
int main()
{




	Window window(u8"Hello你好مرحباこんにちは", 400, 400);

	Renderer* r = new RendererGL();
	r->Initialize(window.GetWindowHandle());

	glEnable(GL_TEXTURE_2D);
	glClearColor(0.05, 0.05, 0.05, 1);


	texd = r->CreateTexture();
	texd->SetFiltering(TextureFilter::AnisotropicNearest, 16.0f);


	// tex

	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);

	//GLubyte tdx[] = {
	//	0, 0, 0, 255 ,       255, 0, 255, 255,
	//	255, 0, 255, 255,     0, 0, 0, 255
	//};
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, tdx);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// en

	while (true)
	{
		window.Update();
		Update();
		Render();
		((RendererGL*)r)->context->SwapBuffers(); // lol
	}

	std::getchar();
}
