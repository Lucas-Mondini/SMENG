workspace "SMENG"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Includes to root (SolutionDir)
IncludeDir = {}
IncludeDir["GLFW"] = "SMENG/vendor/GLFW/include"

include "SMENG/vendor/GLFW"

project "SMENG" 
	location "SMENG"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "spch.h"
	pchsource "%{prj.name}/src/spch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/SPDLog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect"C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
		"SEG_PLATAFORM_WINDOWS",
		"SEG_BUILD_DLL"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "SEG_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "SEG_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "SEG_DIST"
			optimize "On"


project "Sandbox" 
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"SMENG/vendor/SPDLog/include",
		"SMENG/src"
	}
	
	links{
		"SMENG"
	}

	filter "system:windows"
		cppdialect"C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
		"SEG_PLATAFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "SEG_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "SEG_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "SEG_DIST"
			optimize "On"
