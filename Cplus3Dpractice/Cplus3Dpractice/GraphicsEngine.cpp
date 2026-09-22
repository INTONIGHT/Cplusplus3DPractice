#include "GraphicsEngine.h"
#include "RenderSystem.h"
using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	//this is a way of also having swap chain ptr if using this make sure to comment out the method in 
	//the swap chain.cpp file where it calls make swap chain
	/*{
		SwapChainPtr sc{};
		{
			auto sys = std::make_shared<RenderSystem>(RenderSystemDesc{ m_logger });
			sc = sys->createSwapChain({ });
		}
	}*/
	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

RenderSystem& dx3d::GraphicsEngine::getRenderSystem() const noexcept
{
	return *m_renderSystem;
}
