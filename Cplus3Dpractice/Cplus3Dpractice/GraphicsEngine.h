#pragma once
#include "Base.h"
#include "Core.h"

namespace dx3d {

	//prevents it from being further defined by other classes
	class GraphicsEngine final: public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine();

		GraphicsDevice& getGraphicsDevice() const noexcept;

		void render(SwapChain& swapChain);
	private:
		std::shared_ptr<GraphicsDevice> m_graphicsDevice{};
		DeviceContextPtr m_deviceContext{};

	};

}