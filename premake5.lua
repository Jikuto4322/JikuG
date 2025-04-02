workspace "JikuG"
    architecture "x64"
    startproject "Sandbox"

    configurations 
    { 
        "Debug", 
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "JikuG/vendor/GLFW/include"

include "JikuG/vendor/GLFW"

project "JikuG"
    location "JikuG"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "jgpch.h"
    pchsource "JikuG/src/jgpch.cpp"

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

    filter "system:windows"
        architecture "x64"
        cppdialect "c++17"
        staticruntime "Off"
        systemversion "latest"

        defines 
        { 
            "JG_PLATFORM_WINDOWS",
            "JG_BUILD_DLL"
        }

        buildoptions 
        { 
            "/utf-8" 
        }

        postbuildcommands 
        { 
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        runtime "Debug"
        defines { "JG_DEBUG" }
        symbols "On"
        buildoptions { "/MDd" }
        

    filter "configurations:Release"
        runtime "Release"
        defines { "JG_RELEASE" }
        optimize "On"
        buildoptions { "/MD" }

    filter "configurations:Dist"
        defines { "JG_DIST" }
        optimize "On"


project "Sandbox"
    location "Sandbox"
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
        "JikuG/src",
        "JikuG/vendor/spdlog/include"
    }

    links
    {
        "JikuG"
    }

    buildoptions 
    { 
        "/utf-8" 
    }

    filter "system:windows"
        cppdialect "c++17"
        architecture "x64"
        staticruntime "On"
        systemversion "latest"

        defines 
        { 
            "JG_PLATFORM_WINDOWS"
        }

    debugdir ("%{wks.location}/bin/" .. outputdir .. "/Sandbox")
    debugcommand ("%{wks.location}/bin/" .. outputdir .. "/Sandbox/Sandbox.exe")    
    
    filter "configurations:Debug"
        defines { "JG_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "JG_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "JG_DIST" }
        optimize "On"

