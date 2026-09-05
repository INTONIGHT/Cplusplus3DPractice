#include "SwapChain.h"

dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc) : 
	GraphicsResource(gDesc)
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};
	//canvas where the canvas will be rendered
	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	//defined the canvas color format red green blue and alpha  where alpha controls transparency 
	//normalized unsigned ints 0-1 range
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8_UNORM;
	dxgiDesc.BufferCount = 2;
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	dxgiDesc.Windowed = TRUE;
	//remember the & is passing the memory address for variables
	DX3DGraphicsLogErrorAndThrow(m_factory.CreateSwapChain(&m_device, &dxgiDesc, &m_swapChain),
		"CreateSwapChain method failed");
}

