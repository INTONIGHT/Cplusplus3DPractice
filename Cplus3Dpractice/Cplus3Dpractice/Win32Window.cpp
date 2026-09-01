#include "Window.h"
#include <Windows.h>
#include <stdexcept>


dx3d::Window::Window(): Base()
{
	//the L before the stream is needed and here we are setting the params for the wndclass
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DX3DWindow";
	wc.lpfnWndProc = DefWindowProc;
	//this needs to be a pointer to the windclass
	auto windowClassId = RegisterClassEx(&wc);
	//we need this rectangle to automatically handle how the window is rendered on screen then pull those variables for when the window is created
	if (!windowClassId) {
		throw std::runtime_error("RegisterClassEx failed");
	}

	RECT rc{ 0,0,1280,720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	//create a window with specific params
	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"Title here | C++ 3D game",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!m_handle) {
		throw std::runtime_error("CreateWindowEx failed");
	}
	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
