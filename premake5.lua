
workspace "KEngine"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KEngine"
	
	location "KEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("%{prj.name}/Binaries/" .. outputdir .. "/")
	objdir ("%{prj.name}/Intermediate/" .. outputdir .. "/")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"KE_PLATFORM_WINDOWS",
			"KE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.abspath} ../KSandbox/Binaries/" .. outputdir .. "/")
		}


	filter "configurations:Debug"
		defines "KE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "KE_DISTRIBUTION"
		optimize "On"


project "KSandbox"
	
	location "KSandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{prj.name}/Binaries/" .. outputdir .. "/")
	objdir ("%{prj.name}/Intermediate/" .. outputdir .. "/")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"KEngine/Source",
		"KEngine/ThirdParty/spdlog/include"
	}

	links
	{
		"KEngine"
	}

	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"KE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "KE_DISTRIBUTION"
		optimize "On"