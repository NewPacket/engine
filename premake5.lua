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
IncludeDir["Glad"] = "Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "Engine/vendor/DearImGui"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"
include "Engine/vendor/DearImGui"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"GLFW",
		"Glad",
		"DearImGUI",
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
			"EX_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "EX_DIST"
		buildoptions "/MD"
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
		"Engine/vendor/GLFW/include",
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "EX_DIST"
		buildoptions "/MD"
		optimize "On"
