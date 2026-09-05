#include "Window.h"
#include <Windows.h>
#include <stdexcept>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {

	case WM_CLOSE :
	{
		//request to terminate the application
		PostQuitMessage(0);
		break;
	}
	default :
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}


dx3d::Window::Window(const WindowDesc& desc): Base(desc.base) , m_size(desc.size)
{
	//creating a lambda function
	auto registerWindowClassFunction = []() {
		//the L before the stream is needed and here we are setting the params for the wndclass
		WNDCLASSEX wc{};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpszClassName = L"DX3DWindow";
		wc.lpfnWndProc = &WindowProcedure;
		//this needs to be a pointer to the windclass
		return RegisterClassEx(&wc);
		};

	static const auto windowClassId = std::invoke(registerWindowClassFunction);
	
	//we need this rectangle to automatically handle how the window is rendered on screen then pull those variables for when the window is created
	if (!windowClassId) {
		DX3DLogErrorAndThrow("RegisterClassEx failed");
	}

	RECT rc{ 0,0,m_size.width,m_size.height };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	//create a window with specific params
	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"Title here | C++ 3D game",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!m_handle) {
		DX3DLogErrorAndThrow("CreateWindowEx failed");
	}
	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
