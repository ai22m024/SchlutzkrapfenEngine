workspace "SchlutzkrapfenEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SchlutzkrapfenEngine"
	location "SchlutzkrapfenEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"SK_PLATFORM_WINDOWS",
			"SK_BUILD_DLL",
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SK_DIST"
		symbols "On"
	
project "Game"
	location "Game"

	kind "ConsoleApp"
		language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs		
	{
		"SchlutzkrapfenEngine/vendor/spdlog/include",
		"SchlutzkrapfenEngine/src"
	}

	links {
		"SchlutzkrapfenEngine"	
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"SK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SK_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SK_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SK_DIST"
		symbols "On"
