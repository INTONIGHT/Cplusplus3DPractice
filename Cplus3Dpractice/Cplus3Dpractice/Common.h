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
		GraphicsDevice& graphicsDevice;
	};
	struct GraphicsEngineDesc {
		BaseDesc base;
	};
	struct GraphicsDeviceDesc {
		BaseDesc base;
	};
	struct SwapChainDesc {
		void* winHandle{};
		Rect winSize{};
	};
	enum class ShaderType {
		VertexShader = 0,
		PixelShader
	 };

	struct ShaderCompileDesc {
		//aBI safe application binary interface-> memory allocation size across compilers
		//this is important for shaders 
		const char* shaderSourceName{};
		const char* shaderSourceCode{};
		size_t shaderSourceCodeSize{};
		const char* shaderEntryPoint{};
		ShaderType shaderType{};
	};

	struct ShaderBinaryData {
		const void* data{};
		size_t dataSize{};
	};

	struct GraphicsPipelineStateDesc {
		const ShaderBinary& vs;
		const ShaderBinary& ps;
	};

	struct GameDesc {
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};
}
