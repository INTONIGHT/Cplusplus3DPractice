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
	private:
		std::unique_ptr<RenderSystem> m_renderSystem{};

	};

}