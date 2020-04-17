workspace "os"
	configurations { "Debug" }

gccprefix "i686-elf-"

targetdir "build/%{prj.name}/bin/%{cfg.buildcfg}"
objdir "build/%{prj.name}/obj"

filter { "action:gmake*" }
	buildoptions { "-c -std=gnu99 -ffreestanding -O2 -Wall -Wextra" }
	linkoptions { "-ffreestanding", "-O2", "-nostdlib" }

filter { "configurations:Debug" }
	defines { "DEBUG" }
	symbols "On"


project "kernel"
	kind "ConsoleApp"
	language "C"
	location "kernel"
	includedirs { "*/include" }

	links { "k" }

	files { "%{prj.location}/**.o",
			"%{prj.location}/**.h",
			"%{prj.location}/**.hpp",
			"%{prj.location}/**.c",
			"%{prj.location}/**.cpp",
			"%{prj.location}/**.s" }
	
project "k"
	kind "StaticLib"
	language "C"
	location "libc"
	includedirs { "libc/include" }

	files { "%{prj.location}/**.o",
			"%{prj.location}/**.h",
			"%{prj.location}/**.hpp",
			"%{prj.location}/**.c",
			"%{prj.location}/**.cpp",
			"%{prj.location}/**.s" }
