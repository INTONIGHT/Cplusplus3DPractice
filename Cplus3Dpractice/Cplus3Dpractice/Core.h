#pragma once
#include <stdexcept>
#include <memory>


namespace dx3d {
	//allows declaration of classes without needing to actually go through entire class
	class Base;
	class Window;
	class Game;

	class GraphicsEngine;
	class RenderSystem;

	class Logger;

	//for our entire namespace we can use these substitutions
	using i32 = int;
	using ui32 = unsigned int;
	using f32 = float;
	using d64 = double;
}