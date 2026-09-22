#include "DeviceContext.h"
#include "SwapChain.h"

dx3d::DeviceContext::DeviceContext(const GraphicsResourceDesc& gDesc): GraphicsResource(gDesc)
{


	DX3DGraphicsLogThrowOnFail(m_device.CreateDeferredContext(0, &m_context),
		"CreateDeferredContext method failed");
}

void dx3d::DeviceContext::clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color)
{
	//float array for colors
	f32 fColor[] = { color.x,color.y,color.z,color.w };
	auto rtv = swapChain.m_rtv.Get();
	//clear a particular object. clear and fill back buffer
	//in c++ a friend class is allowed to access private and protected methods of asnother class
	//bypass encapsulation in a controlled way device context and swap chain are tightly coupled
	//using friend class is discouraged as it breaks encapsulation only use in special cases like this
	m_context->ClearRenderTargetView(rtv, fColor);
	//last param will get covered later on
	m_context->OMSetRenderTargets(1, &rtv, nullptr);
}
