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
		void log(LogLevel level, const char* message);
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

}

#define DX3DLog(logger,type,message)\
logger.log((type),message)

#define DX3DLogThrow(logger,exception,type,message)\
{\
DX3DLog(logger,type,message);\
throw exception(message);\
}
