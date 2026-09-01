#include "Game.h"
#include "Window.h"



dx3d::Game::Game()
{
	m_display = std::make_unique<Window>();

	//shallow copy of object underlining sources avoid this
	//for any component
	//if you try to copy the window object after updating base the compilation will fail as it will be forbidden
	//Window win{};
	//auto w = win;
}

dx3d::Game::~Game()
{
	
}


