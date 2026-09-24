#include "GraphicsDevice.h"
#include "GraphicsLogUtils.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "ShaderBinary.h"
#include "GraphicsPipelineState.h"

using namespace dx3d;
//note its not always ideal to use using namespace especially in header files it can cause name collisions
//only do using namespace in .cpp files



dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc): Base(desc.base)
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
	DX3DGraphicsLogThrowOnFail (D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION,
		&m_d3dDevice, &featureLevel, &m_d3dContext),"Direct3D11 initialization failed");

	//asks if an oibject supports an interface and then call a pointer to that interface
	DX3DGraphicsLogThrowOnFail(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		"QueryInterface failed to retrieve IDXGIDevice");

	//we now call get parent and fetch the GPU info
	DX3DGraphicsLogThrowOnFail(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"GetParent failed to retrieve IDXGIAdapter");

	//we call get parent to get the dxgi factory
	DX3DGraphicsLogThrowOnFail(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"GetParent failed to retrieve IDXGIFactory");

	
}

dx3d::GraphicsDevice::~GraphicsDevice()
{
}

SwapChainPtr dx3d::GraphicsDevice::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc,getGraphicsResourceDesc());
}

DeviceContextPtr dx3d::GraphicsDevice::createDeviceContext()
{
	return std::make_shared<DeviceContext>(getGraphicsResourceDesc());
}

ShaderBinaryPtr dx3d::GraphicsDevice::compileShader(const ShaderCompileDesc& desc)
{
	return std::make_shared<ShaderBinary>(desc, getGraphicsResourceDesc());
}

GraphicsPipelineStatePtr dx3d::GraphicsDevice::createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc)
{
	return std::make_shared<GraphicsPipelineState>(desc, getGraphicsResourceDesc());
}

void dx3d::GraphicsDevice::executeCommandList(DeviceContext& context)
{
	Microsoft::WRL::ComPtr<ID3D11CommandList> list{};
	//restores state with teh bool flag
	DX3DGraphicsLogThrowOnFail(context.m_context->FinishCommandList(false, &list),
		"context.m_context->FinishCommandList failed");
	//for effeciency pass false
	m_d3dContext->ExecuteCommandList(list.Get(), false);
}

GraphicsResourceDesc dx3d::GraphicsDevice::getGraphicsResourceDesc() const noexcept
{
	return { {m_logger},shared_from_this(), *m_d3dDevice.Get() , *m_dxgiFactory.Get() };
}
