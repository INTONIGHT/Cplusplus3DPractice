#include "GraphicsEngine.h"
#include "RenderSystem.h"

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	m_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{m_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}
