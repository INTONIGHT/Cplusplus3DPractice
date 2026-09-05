#pragma once
#include "Window.h"

namespace dx3d {

	//we can have this class actually handling all the 3D graphics for our window
	class Display final: public Window
	{
	public :
		explicit Display(const DisplayDesc& desc);


	private :
		SwapChainPtr m_swapChain{};
	};
}
