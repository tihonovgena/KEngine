#pragma once


#include "Core/CoreMacros.h"

namespace KEngine 
{
	class KENGINE_API Application
	{
	public:

		Application();

		virtual ~Application();

		virtual void Run();
	};


	Application* CreateApplication();
}



