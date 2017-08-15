#include <iostream>

#include "Platform/Window.h"

#include "RendererGL.h"
#include "GL/glew.h"

float rt = 0.0f;

void Update()
{
}
void Render()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	glRotatef(rt, 0, 0, 1);
	rt += 0.5f;

	glBegin(GL_TRIANGLES);

	glVertex3f(-0.5f, -0.5f, 0.0f);//triangle one first vertex
	glColor3f(1, 0, 0);

	glVertex3f(0, 0.5, 0.0f);//triangle one second vertex
	glColor3f(0, 1, 0);

	glVertex3f(0.5, -0.5, 0.0f);//triangle one third vertex
	glColor3f(0, 0, 1);


	glEnd();

	
}
int main()
{




	Window window(u8"Hello你好مرحباこんにちは", 400, 400);

	Renderer* r = new RendererGL();
	r->Initialize(window.GetWindowHandle());

	glClearColor(0.05, 0.05, 0.05, 1);

	while (true)
	{
		window.Update();
		Update();
		Render();
		((RendererGL*)r)->context->SwapBuffers(); // HA
	}

	std::getchar();
}
