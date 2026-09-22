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
		~Logger();
		void log(LogLevel level, const char* message) const;
	protected:
		//rule of 5 methods where we implement 5 methods
		//we prevent it from being copied or moved in any way
		//this prevents any logger from being accidentally overwritten with a new logger
		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator = (const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;
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

#define DX3DLogInfo(message)\
	getLogger().log((Logger::LogLevel::Info), message);

#define DX3DLogWarning(message)\
	getLogger().log((Logger::LogLevel::Warning), message);
}
