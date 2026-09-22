#pragma once
#include "GraphicsResource.h"


namespace dx3d {


	class SwapChain final: public GraphicsResource
	{
	public :
		SwapChain(const SwapChainDesc& desc,const GraphicsResourceDesc& gDesc);
	private:
		void reloadBuffers();
	private :
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv{};

		//this lets device context access these methods without directly calling it . BE CAREFUl on using friend class
		friend class DeviceContext;
	};
}
