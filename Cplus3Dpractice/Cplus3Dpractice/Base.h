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
		virtual Logger& getLogger()  noexcept final;
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
#define DX3DLogError(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Error, message);
//this is used to create macros
//multi lined macros need a backslash at the end of each line
#define DX3DLogThrowError(message)\
DX3DLogThrow(getLogger(),std::runtime_error, Logger::LogLevel::Error, message);

#define DX3DLogInfo(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Info, message)

#define DX3DLogWarning(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Warning, message)

#define DX3DLogThrowInvalidArg(message)\
DX3DLogThrow(getLogger(),std::invalid_argument, Logger::LogLevel::Error, message);