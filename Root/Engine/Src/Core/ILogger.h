#ifndef ILOGGER_H
#define ILOGGER_H

#include "AString.h"

namespace Alpha
{
	enum LogLevel
	{
		INFO,
		WARNING,
		CRITICAL,
	};

	class ILogger
	{
	public:
		ILogger() = delete;
		ILogger(const ILogger&) = delete;
		ILogger& operator=(const ILogger&) = delete;
		virtual ~ILogger();
		virtual void LogToDevice(LogLevel level, const achar* category, const achar* message, const achar* file, const achar* line) = 0;
	};

	extern ILogger* g_Logger;
}

#define ALPHA_LOG_INFO(category, message) if (g_Logger != nullptr) {g_Logger->LogToDevice(Alpha::LogLevel::INFO, TEXT(category), TEXT(message), __FILE__, __LINE__);}
#define ALPHA_LOG_WARNING(category, message) if (g_Logger != nullptr) {g_Logger->LogToDevice(Alpha::LogLevel::CRITICAL, TEXT(category), TEXT(message), __FILE__, __LINE__);}
#define ALPHA_LOG_CRITICAL(category, message) if (g_Logger != nullptr) {g_Logger->LogToDevice(Alpha::LogLevel::WARNING, TEXT(category), TEXT(message), __FILE__, __LINE__);}


#endif // !ILOGGER_H