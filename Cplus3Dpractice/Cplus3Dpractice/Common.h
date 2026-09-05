#pragma once
#include "Core.h"
#include "Logger.h"
#include "Rect.h"


namespace dx3d {
	struct BaseDesc {
		Logger& logger;
	};
	struct WindowDesc {
		BaseDesc base;
		Rect size{};
	};
	struct DisplayDesc {
		WindowDesc window;
		RenderSystem& renderSystem;
	};
	struct GraphicsEngineDesc {
		BaseDesc base;
	};
	struct RenderSystemDesc {
		BaseDesc base;
	};
	struct SwapChainDesc {
		void* winHandle{};
		Rect winSize{};
	};


	struct GameDesc {
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};
}
