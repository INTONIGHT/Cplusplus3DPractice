#pragma once
#include "Base.h"

namespace dx3d {


	class Window: public Base
	{
	public : 
		Window();
		virtual ~Window() override;

	private :
		//dont want to give wplatform specific definitions such as the api stuff
		void* m_handle{};
	};
}
