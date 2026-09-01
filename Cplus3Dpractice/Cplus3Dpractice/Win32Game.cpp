#include "Game.h"
#include <Windows.h>


void dx3d::Game::run()
{
	MSG msg{};
	while (m_isRunning) {
		//handle the message queue
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//do this to stop unnecessary speed usage
		Sleep(1);
	}
}