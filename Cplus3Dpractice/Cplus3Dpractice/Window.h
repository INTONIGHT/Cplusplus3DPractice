#pragma once
#include "Base.h"
#include "Common.h"

namespace dx3d {


	class Window: public Base
	{
	public : 
		explicit Window(const WindowDesc& desc);
		virtual ~Window() override;

	private :
		//dont want to give wplatform specific definitions such as the api stuff
		void* m_handle{};
	};
}
