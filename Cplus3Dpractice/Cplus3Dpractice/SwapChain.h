#pragma once
#include "GraphicsResource.h"


namespace dx3d {


	class SwapChain final: public GraphicsResource
	{
	public :
		SwapChain(const SwapChainDesc& desc,const GraphicsResourceDesc& gDesc);
		Rect getSize() const noexcept;
		//vsync is used to synchronize frame rate with monitor ensures frames are displayed smoothly
		void present(bool vsync = false);
	private:
		void reloadBuffers();
	private :
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv{};
		Rect m_size{};

		//this lets device context access these methods without directly calling it . BE CAREFUl on using friend class
		friend class DeviceContext;
	};
}
