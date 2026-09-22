#include "GraphicsEngine.h"
#include "GraphicsDevice.h"
using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	//this is a way of also having swap chain ptr if using this make sure to comment out the method in 
	//the swap chain.cpp file where it calls make swap chain
	/*{
		SwapChainPtr sc{};
		{
			auto sys = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{ m_logger });
			sc = sys->createSwapChain({ });
		}
	}*/
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice() const noexcept
{
	return *m_graphicsDevice;
}
