workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
currentSysVer = "latest"

--Include dirs relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"

include "Engine/vendor/GLFW"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir.."/%{prj.name}")
	objdir("bin-int/".. outputdir.."/%{prj.name}")

	pchheader "eng_pch.h"
	pchsource "Engine/src/eng_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter  "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion (currentSysVer)

		defines 
		{
			"EX_PLATFORM_WIN",
			"EX_BUILD_DLL",
			"EX_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EX_DIST"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/".. outputdir.."/%{prj.name}")
	objdir("bin-int/".. outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine/vendor/spdlog/include",
		"Engine/src"
	}

	links
	{
		"Engine"
	}

	filter  "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion (currentSysVer)

		defines 
		{
			"EX_PLATFORM_WIN"
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EX_DIST"
		optimize "On"
