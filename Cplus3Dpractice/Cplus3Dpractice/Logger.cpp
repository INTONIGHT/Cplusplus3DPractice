#include "Logger.h"
#include <iostream>

dx3d::Logger::Logger(LogLevel logLevel): m_logLevel(logLevel)
{

}

void dx3d::Logger::log(LogLevel level, const char* message) const
{
	auto logLevelToString = [](LogLevel level) {
		switch (level) {
		case LogLevel::Info: return "Info";
		case LogLevel::Warning: return "Warning";
		case LogLevel::Error: return "Error";
		default: return "Unknown";
		}
		};


	if (level > m_logLevel) return;
	std::clog << "{DX30" << logLevelToString(level) << "]:" << message << "\n";
}
