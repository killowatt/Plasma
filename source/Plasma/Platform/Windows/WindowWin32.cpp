#include "WindowWin32.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WindowWin32* Window = (WindowWin32*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	switch (message)
	{
	case WM_CLOSE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

void WindowWin32::Update()
{
	MSG message;
	while (PeekMessage(&message, handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

void WindowWin32::Close()
{
	DestroyWindow(handle);
}

WindowWin32::WindowWin32(const char* title, int width, int height) // TODO: this impl sucks
{
	instance = GetModuleHandle(0);


	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	//wc.style = CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = instance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"Plasma";

	RegisterClassEx(&wc);





	DWORD style = WS_VISIBLE;
	style |= WS_CAPTION | WS_MINIMIZEBOX;

	wchar_t* wideTitle = new wchar_t[strlen(title) + 1];
	MultiByteToWideChar(CP_UTF8, 0, title, -1, wideTitle, strlen(title) + 1);

	RECT windowRect = { 0, 0, width, height };
	AdjustWindowRect(&windowRect, style, false);

	HDC scDC = GetDC(NULL);
	int left = (GetDeviceCaps(scDC, HORZRES) - static_cast<int>(width)) / 2;
	int top = (GetDeviceCaps(scDC, VERTRES) - static_cast<int>(height)) / 2;
	width = windowRect.right - windowRect.left;
	height = windowRect.bottom - windowRect.top;
	ReleaseDC(NULL, scDC);

	handle = CreateWindow(
		L"Plasma",
		wideTitle,
		style,
		left, top,
		width, height,
		NULL,
		NULL,
		instance,
		NULL
	);

	delete wideTitle;

	SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow(handle, 5);
	UpdateWindow(handle);
}