#include "RenderSystem.h"
#include "GraphicsLogUtils.h"
#include "SwapChain.h"
using namespace dx3d;
//note its not always ideal to use using namespace especially in header files it can cause name collisions
//only do using namespace in .cpp files



dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc): Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};

	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	//used for all the graphics rendered to the window
	//the ID3D11device part handles feeatures textures shaders etc
	//device context is similar to how the device is also handled
	//you could include an invalid value in here such as -1 after the null to purposely hit the log message
	DX3DGraphicsLogErrorAndThrow (D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION,
		&m_d3dDevice, &featureLevel, &m_d3dContext),"Direct3D11 initialization failed");

	//asks if an oibject supports an interface and then call a pointer to that interface
	DX3DGraphicsLogErrorAndThrow(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		"QueryInterface failed to retrieve IDXGIDevice");

	//we now call get parent and fetch the GPU info
	DX3DGraphicsLogErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"GetParent failed to retrieve IDXGIAdapter");

	//we call get parent to get the dxgi factory
	DX3DGraphicsLogErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"GetParent failed to retrieve IDXGIFactory");


}

dx3d::RenderSystem::~RenderSystem()
{
}

SwapChainPtr dx3d::RenderSystem::createSwapChain(const SwapChainDesc& desc)
{
	return std::make_shared<SwapChain>(desc,getGraphicsResourceDesc());
}

GraphicsResourceDesc dx3d::RenderSystem::getGraphicsResourceDesc()
{
	return { {m_logger}, *m_d3dDevice.Get() , *m_dxgiFactory.Get() };
}
