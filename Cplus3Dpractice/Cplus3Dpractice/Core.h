#pragma once
#include <stdexcept>
#include <memory>


namespace dx3d {
	//allows declaration of classes without needing to actually go through entire class
	class Base;
	class Window;
	class Game;

	class GraphicsEngine;
	class GraphicsDevice;

	class Logger;
	class SwapChain;
	class Display;
	class DeviceContext;
	class ShaderBinary;
	class GraphicsPipelineState;
	class VertexBuffer;


	//for our entire namespace we can use these substitutions
	using i32 = int;
	using ui32 = unsigned int;
	using f32 = float;
	using d64 = double;

	//how many pointers are referencing the same object only destroyed when last pointer is destroyed or reset
	using SwapChainPtr = std::shared_ptr<SwapChain>;
	using DeviceContextPtr = std::shared_ptr<DeviceContext>;
	using ShaderBinaryPtr = std::shared_ptr<ShaderBinary>;
	using GraphicsPipelineStatePtr = std::shared_ptr<GraphicsPipelineState>;
	using VertexBufferPtr = std::shared_ptr<VertexBuffer>;
}