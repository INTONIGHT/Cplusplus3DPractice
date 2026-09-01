#pragma once
#include "Base.h"

namespace dx3d {

	//prevents it from being further defined by other classes
	class GraphicsEngine final: public Base
	{
	public:
		GraphicsEngine();
		virtual ~GraphicsEngine();
	};

}