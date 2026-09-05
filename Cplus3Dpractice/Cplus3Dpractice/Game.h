#pragma once
#include "Base.h"
#include "Core.h"

namespace dx3d {


	class Game: public Base
	{
	public : 
		explicit Game(const GameDesc& desc);
		virtual ~Game() override;

		virtual void run() final;
	private :
		//order is important HERE!!!!!!! last defined attribute is first to be deallocated
		std::unique_ptr<Logger> m_loggerPtr{};
		std::unique_ptr<GraphicsEngine> m_graphicsEngine{};
		std::unique_ptr<Display> m_display{};
		bool m_isRunning{ true };
	};
}
