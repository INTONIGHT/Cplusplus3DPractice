#include "Game.h"
#include "Window.h"



dx3d::Game::Game()
{
	m_display = new Window();
}

dx3d::Game::~Game()
{
	delete m_display;
}


