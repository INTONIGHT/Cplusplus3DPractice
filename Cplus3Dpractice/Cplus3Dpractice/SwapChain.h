#pragma once
#include "GraphicsResource.h"

namespace dx3d {


	class SwapChain final: public GraphicsResource
	{
	public :
		SwapChain(const GraphicsResourceDesc& desc);
	};
}
