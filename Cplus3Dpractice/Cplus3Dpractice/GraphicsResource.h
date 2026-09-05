#pragma once
#include "Base.h"
#include <d3d11.h>
#include "Common.h"
#include <wrl.h>
#include "GraphicsLogUtils.h"

namespace dx3d {

	struct GraphicsResourceDesc{
		BaseDesc base;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};

	class GraphicsResource : public Base
	{
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& desc): 
			Base(desc.base),
			m_device(desc.device),
			m_factory(desc.factory)
		{

		}
	protected:
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};
}