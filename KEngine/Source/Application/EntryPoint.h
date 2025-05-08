#pragma once

#include "Application.h"
#include "Core/Log.h"

#ifdef KE_PLATFORM_WINDOWS

extern KEngine::Application* KEngine::CreateApplication();

int main(int argc, char** argv)
{
	KEngine::Log::Init();
	
	KEngine::Application* Application = KEngine::CreateApplication();
	Application->Run();
	delete Application;
	return 1;
}

#endif // KE_PLATFORM_WINDOWS
