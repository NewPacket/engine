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

startproject "Sandbox"

--Include dirs relative to root folder
engineVendorPath = "Engine\\vendor\\"

IncludeDir = {}
IncludeDir["spdlog"] = engineVendorPath .. "spdlog\\include"
IncludeDir["GLFW"]   = engineVendorPath .. "GLFW\\include"
IncludeDir["Glad"]   = engineVendorPath .. "Glad\\include"
IncludeDir["ImGui"]  = engineVendorPath .. "DearImGUI"
IncludeDir["glm"] 	 = engineVendorPath .. "glm"

group "Dependencies"
	include (engineVendorPath .. "GLFW")
	include (engineVendorPath .. "Glad")
	include (engineVendorPath .. "DearImGui")
group ""

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin\\".. outputdir.."\\%{prj.name}")
	objdir("bin-int\\".. outputdir.."\\%{prj.name}")

	pchheader "eng_pch.h"
	pchsource "Engine/src/eng_pch.cpp"

	files
	{
		"%{prj.name}\\src\\**.h",
		"%{prj.name}\\src\\**.cpp",
		"%{prj.name}\\vendor\\glm\\glm\\**.hpp",
		"%{prj.name}\\vendor\\glm\\glm\\**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"GLFW",
		"Glad",
		"DearImGUI",
		"opengl32.lib"
	}

	buildoptions {"/MP"}

	filter  "system:windows" 
		cppdialect "C++17"
		systemversion (currentSysVer)

		defines 
		{
			"EX_PLATFORM_WIN",
			"EX_BUILD_DLL",
			"EX_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EX_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin\\".. outputdir.."\\%{prj.name}")
	objdir("bin-int\\".. outputdir.."\\%{prj.name}")

	files
	{
		"%{prj.name}\\src\\**.h",
		"%{prj.name}\\src\\**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"Engine\\src"
	}

	links
	{
		"Engine"
	}

	buildoptions {"/MP"}
	filter  "system:windows" 
		cppdialect "C++17"
		systemversion (currentSysVer)

		defines 
		{
			"EX_PLATFORM_WIN"
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EX_DIST"
		runtime "Release"
		optimize "on"
