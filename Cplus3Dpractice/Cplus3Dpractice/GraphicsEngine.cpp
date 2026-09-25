#include "GraphicsEngine.h"
#include "GraphicsDevice.h"
#include "DeviceContext.h"
#include "SwapChain.h"
#include "Vec3.h"
#include "VertexBuffer.h"

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
	//using constexpr keyword as it lets the compile calculate at compile time
	//rho string literal preserves characters as written. you can use R"()" between the () you can write the actual code
	//within the code blocks the vsmain is the entry point for vertex shaders and ps main is for pixel shader
	//the semantic sv_position is needed semantic are needed for the GPU
	//the pixel shader controls the color that is written for the pixels
	constexpr char shaderSourceCode[] =
		R"(
		float4 VSMain(float3 pos: POSITION): SV_Position
		{
		return float4(pos.xyz, 1.0);
		}
		float4 PSMain(): SV_Target
		{
		return float4(1.0,1.0,1.0,1.0);
		}
		)";
	constexpr char shaderSourceName[] = "Basic";
	constexpr auto shaderSourceCodeSize = std::size(shaderSourceCode);

	//pass the entry point name as well and the shader type we want to compile
	auto vs = device.compileShader({shaderSourceName, shaderSourceCode, shaderSourceCodeSize,
		"VSMain",ShaderType::VertexShader});

	auto ps = device.compileShader({ shaderSourceName, shaderSourceCode, shaderSourceCodeSize,
		"PSMain",ShaderType::PixelShader });

	m_pipeline = device.createGraphicsPipelineState({ *vs,*ps });

	//these values represent each point on screen and should be between 0 and 1 or -1 and 0 
	const Vec3 vertexList[] = {
		{-0.5f,-0.5f,0.0f},
		{0.0f,0.5f,0.0f},
		{0.5f,-0.5f,0.0f}
	};
	//just the size of the class in bytes for that last one
	m_vb = device.createVertexBuffer({vertexList,std::size(vertexList),sizeof(Vec3)});
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
	context.setGraphicsPipelineState(*m_pipeline);

	context.setViewportSize(swapChain.getSize());
	//input stage
	auto& vb = *m_vb;
	context.setVertexBuffer(vb);
	//can only be called after the pipeline is set
	context.drawTriangleList(vb.getVertexListSize(), 0u);

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);
	swapChain.present();

}
