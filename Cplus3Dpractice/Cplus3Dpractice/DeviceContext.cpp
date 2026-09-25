#include "DeviceContext.h"
#include "SwapChain.h"
#include "GraphicsPipelineState.h"
#include "VertexBuffer.h"

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

void dx3d::DeviceContext::setGraphicsPipelineState(const GraphicsPipelineState& pipeline)
{
	//binds shader to gpu pipeline basically tell the gpu to use the shader
	m_context->VSSetShader(pipeline.m_vs.Get(), nullptr, 0);
	m_context->PSSetShader(pipeline.m_ps.Get(), nullptr, 0);

}

void dx3d::DeviceContext::setVertexBuffer(const VertexBuffer& buffer)
{
	auto stride = buffer.m_vertexSize;
	auto buf = buffer.m_buffer.Get();
	auto offset = 0u;
	//how to tell the gpu where the buffer data is stored and interpret it
	m_context->IASetVertexBuffers(0, 1, &buf, &stride, &offset);
}
