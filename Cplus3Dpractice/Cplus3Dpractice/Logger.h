#pragma once

namespace dx3d {


	class Logger final
	{
	public:
		enum class LogLevel {
			Error = 0,
			Warning,
			Info
		};
		//follow rule of 0
		explicit Logger(LogLevel logLevel = LogLevel::Error);
		void log(LogLevel level, const char* message) const;
	private:
		LogLevel m_logLevel = LogLevel::Error;
	};
#define DX3DLogError(message)\
getLogger().log((Logger::LogLevel::Error), message);
	//this is used to create macros
	//multi lined macros need a backslash at the end of each line
#define DX3DLogErrorAndThrow(message)\
{\
	DX3DLogError(message);\
	throw std::runtime_error(message);\
	}


}
