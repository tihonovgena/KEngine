#pragma once

#include "spdlog/spdlog.h"
#include "Core/CoreMacros.h"

namespace KEngine
{
	enum class LogVerbosity
	{
		Trace,
		Info,
		Warning,
		Error,
		Critical
	};


	class KENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return KEngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() { return ApplicationLogger; }

		template<typename... Args>
		static void LogMessage(std::shared_ptr<spdlog::logger> Logger, LogVerbosity level, fmt::format_string<Args...> fmt, Args&&... args)
		{
			if (!Logger) return;

			switch (level)
			{
			case LogVerbosity::Trace:
				Logger->trace(fmt, std::forward<Args>(args)...);
				break;
			case LogVerbosity::Info:
				Logger->info(fmt, std::forward<Args>(args)...);
				break;
			case LogVerbosity::Warning:
				Logger->warn(fmt, std::forward<Args>(args)...);
				break;
			case LogVerbosity::Error:
				Logger->error(fmt, std::forward<Args>(args)...);
				break;
			case LogVerbosity::Critical:
				Logger->critical(fmt, std::forward<Args>(args)...);
				break;
			}
		}

	private:
		static std::shared_ptr<spdlog::logger> KEngineLogger;
		static std::shared_ptr<spdlog::logger> ApplicationLogger;
	};
}

