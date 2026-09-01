#include "GraphicsEngine.h"
#include "RenderSystem.h"

dx3d::GraphicsEngine::GraphicsEngine()
{
	m_renderSystem = std::make_unique<RenderSystem>();
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}
