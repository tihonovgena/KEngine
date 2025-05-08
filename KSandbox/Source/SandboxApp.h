#pragma once


#include "Core/KEngine.h"
#include "stdio.h"

class Sandbox : public KEngine::Application
{

public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	void Run()
	{
		KE_LOG(Info, "Sandbox running");

		KEngine::Application::Run();
	}
};

KEngine::Application* KEngine::CreateApplication()
{
	return new Sandbox();
}

