#pragma once
#include "Base.h"
#include "Core.h"

namespace dx3d {


	class Game: public Base
	{
	public : 
		Game();
		virtual ~Game() override;

		virtual void run() final;
	private :
		Window* m_display{};
		bool m_isRunning{ true };
	};
}
