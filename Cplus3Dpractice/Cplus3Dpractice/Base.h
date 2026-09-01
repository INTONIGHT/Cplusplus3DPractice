#pragma once
//container to group related code classes etc under one name
namespace dx3d {


	class Base
	{
	public : 
		Base();
		//virtual is a special type of destructor 
		virtual ~Base();
	protected:
		//rule of 5 methods where we implement 5 methods
		//we prevent it from being copied or moved in any way
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator=(Base&&) = delete;
	};
}
