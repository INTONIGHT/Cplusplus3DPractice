#include "Game.h"
#include "Window.h"
#include "GraphicsEngine.h"
#include "Logger.h"

//the following code block is an example of what NOT to do
//shallow copy of object underlining sources avoid this
	//for any component
	//if you try to copy the window object after updating base the compilation will fail as it will be forbidden
	//Window win{};
	//auto w = win;
//end example

dx3d::Game::Game()
{
	//attribute order matters here as well
	m_loggerPtr = std::make_unique<Logger>(Logger::LogLevel::Info);
	m_graphicsEngine = std::make_unique<GraphicsEngine>();
	m_display = std::make_unique<Window>();

	m_loggerPtr->log(Logger::LogLevel::Info, "Game initialized.");
}

dx3d::Game::~Game()
{
	m_loggerPtr->log(Logger::LogLevel::Info, "Game shut down.");
}


