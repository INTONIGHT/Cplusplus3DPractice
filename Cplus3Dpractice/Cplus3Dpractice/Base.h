#pragma once
#include "Common.h"


//container to group related code classes etc under one name
namespace dx3d {


	class Base
	{
	public : 
		explicit Base(const BaseDesc& desc);
		//virtual is a special type of destructor 
		virtual ~Base();
		//function doesnt throw exceptions
		virtual Logger& getLogger() const noexcept final;
	protected:
		//rule of 5 methods where we implement 5 methods
		//we prevent it from being copied or moved in any way
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator=(Base&&) = delete;

		//using dependency injection using constructor injection
		//dependency aggregation insert a single object that inserts all dependencies together
	protected:
		Logger& m_logger;
	};
}
