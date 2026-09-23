#include "GraphicsEngine.h"
#include "GraphicsDevice.h"
#include "DeviceContext.h"
#include "SwapChain.h"

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

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice()  noexcept
{
	return *m_graphicsDevice;
}

void dx3d::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *m_deviceContext;
	//setting to red
	context.clearAndSetBackBuffer(swapChain, { 1,0,0,1 });

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);
	swapChain.present();

}
