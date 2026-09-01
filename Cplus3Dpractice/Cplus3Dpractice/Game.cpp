#include "Game.h"
#include "Window.h"



dx3d::Game::Game()
{
	m_display = std::make_unique<Window>();
}

dx3d::Game::~Game()
{
	
}


