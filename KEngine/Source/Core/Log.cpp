#include "Log.h"
#include "LogMacros.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace KEngine 
{
	std::shared_ptr<spdlog::logger> Log::KEngineLogger;
	std::shared_ptr<spdlog::logger> Log::ApplicationLogger;


	// TODO Use application names such as Editor, Sandbox etc.
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] %n:  %v%$");

		KEngineLogger = spdlog::stdout_color_mt("KENGINE");
		KE_CORE_LOG(Info, "log initiated successfully");

		ApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		KE_LOG(Info, "log initiated successful");
	}
}

