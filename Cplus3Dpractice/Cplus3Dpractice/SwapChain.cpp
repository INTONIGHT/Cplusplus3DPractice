#include "SwapChain.h"


dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc) : 
	GraphicsResource(gDesc)
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};
	//canvas where the canvas will be rendered
	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	//defined the canvas color format red green blue and alpha where alpha controls transparency
	//use a common 32-bit RGBA format (8 bits per channel)
	//make sure this is the right format !
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	// sensible defaults for the display mode
	//dxgiDesc.BufferDesc.RefreshRate.Numerator = 60;
	//dxgiDesc.BufferDesc.RefreshRate.Denominator = 1;
	//dxgiDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	//dxgiDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	dxgiDesc.BufferCount = 2;
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	dxgiDesc.Windowed = TRUE;
	// m_swapChain.GetAddressOf()
	DX3DGraphicsLogErrorAndThrow(m_factory.CreateSwapChain(&m_device, &dxgiDesc, &m_swapChain),
		"CreateSwapChain method failed");
}

