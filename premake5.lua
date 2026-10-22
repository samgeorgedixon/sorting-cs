workspace "sorting-cs"
    architecture "x64"
    language "C++"
    cppdialect "C++17"

    startproject "sorting-cs"
    
    configurations { "debug", "release" }

    filter "system:windows"
        systemversion "latest"
        defines "PLATFORM_WINDOWS"
        staticruntime "on"
        entrypoint "mainCRTStartup"
    filter "configurations:debug"
        defines "DEBUG"
        symbols "on"
    filter "configurations:release"
        defines "RELEASE"
        optimize "on"

build = "%{cfg.buildcfg}-%{cfg.system}/"
bin = "%{wks.location}/bin/"
bin_int = "%{wks.location}/bin/bin-int/"

project "console"
    location "console"
    
    targetname "sorting_cs_console"
    targetdir (bin .. "console/" .. build)
    objdir (bin_int .. "console/" .. build)
    
    files {
        "%{prj.location}/src/**.cpp",
        "%{prj.location}/src/**.h"
    }
    includedirs {
        "%{prj.location}/src",
        "engine/src"
    }
    links {
        "engine"
    }

project "engine"
    location "engine"
    kind "StaticLib"
    
    targetname "sorting-cs_engine"
    targetdir (bin .. "engine/" .. build)
    objdir (bin_int .. "engine/" .. build)

    files {
        "%{prj.location}/src/**.cpp",
        "%{prj.location}/src/**.h"
    } 
    includedirs {
        "%{prj.location}/src",
    }
