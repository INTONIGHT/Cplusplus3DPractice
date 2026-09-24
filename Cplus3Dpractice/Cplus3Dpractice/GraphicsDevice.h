#pragma once
#include "Base.h"
#include <d3d11.h>
#include <wrl.h>
#include "Core.h"
#include "Common.h"
#include "GraphicsResource.h"


namespace dx3d {


	class GraphicsDevice final : public Base, public std::enable_shared_from_this<GraphicsDevice>
	{
	public:
		explicit GraphicsDevice(const GraphicsDeviceDesc& desc);
		virtual ~GraphicsDevice() override;

		SwapChainPtr createSwapChain(const SwapChainDesc& desc) const;
		DeviceContextPtr createDeviceContext();
		ShaderBinaryPtr compileShader(const ShaderCompileDesc& desc);
		GraphicsPipelineStatePtr createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc);

		void executeCommandList(DeviceContext& context);
	private:
		GraphicsResourceDesc getGraphicsResourceDesc() const noexcept;
	private:
		//there is a chain that starts with the id3d11 device which is a high level rendering device
		//the idxgidevice is a graphics device bound to the gpu
		//idxgiadapter represents the GPU
		//idxgIfactory manages adapters and creates swap chains
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext{};
		Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxgiAdapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> m_dxgiFactory{};
	};

}