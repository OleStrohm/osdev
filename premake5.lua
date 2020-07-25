workspace "os"
	configurations { "Debug" }

gccprefix "i686-elf-"

targetdir "build/%{prj.name}/bin/%{cfg.buildcfg}"
objdir "build/%{prj.name}/obj"

filter { "action:gmake*" }
	buildoptions { "--sysroot=/home/ole/workspace/os/sysroot", "-isystem=/usr/include", "-MD -c -g -ffreestanding -O2 -Wall -Wextra" }
	linkoptions { "--sysroot=/home/ole/workspace/os/sysroot", "-isystem=/usr/include", "-ffreestanding", "-O2", "-nostdlib", "-lgcc", "-lk" }

filter { "configurations:Debug" }
	defines { "DEBUG" }
	symbols "On"

prebuildmessage "Copying headers"

cleancommands { "rm -rf %{wks.location}/build" }

project "kernel"
	kind "ConsoleApp"
	language "C++"
	location "kernel"
	linkoptions { "-T %{prj.location}/arch/i386/linker.ld", "%{prj.location}/arch/i386/crtbegin.o %{prj.location}/arch/i386/crtend.o" }
	prebuildcommands {
		"mkdir -p %{wks.location}/sysroot/usr/include",
		"cp -RT %{prj.location}/include %{wks.location}/sysroot/usr/include"
	}
	postbuildcommands {
		"mkdir -p %{wks.location}/sysroot/boot",
		"cp %{cfg.buildtarget.relpath} %{wks.location}/sysroot/boot",
		"mkdir -p %{wks.location}/isodir/boot/grub",
		"cp %{cfg.buildtarget.relpath} %{wks.location}/isodir/boot/kernel",
		"echo 'menuentry \"os\" {' > %{wks.location}/isodir/boot/grub/grub.cfg",
		"echo 'multiboot /boot/kernel' >> %{wks.location}/isodir/boot/grub/grub.cfg",
		"echo '}' >> %{wks.location}/isodir/boot/grub/grub.cfg",
		"grub-mkrescue -o %{wks.location}/os.iso %{wks.location}/isodir"
	}
	postbuildmessage "Creating iso"

	links { "k" }

	files {
		"%{prj.location}/**.h",
		"%{prj.location}/**.hpp",
		"%{prj.location}/**.c",
		"%{prj.location}/**.cpp",
		"%{prj.location}/**.s",
		"%{prj.location}/arch/i386/crtbegin.o",
		"%{prj.location}/arch/i386/crtend.o"
		}
	
project "k"
	kind "StaticLib"
	language "C"
	location "libc"

	defines { "__is_libc", "__is_libk" }

	includedirs { "%{prj.location}/include"}
	prebuildcommands {
		"mkdir -p %{wks.location}/sysroot/usr/include",
		"cp -RT %{prj.location}/include %{wks.location}/sysroot/usr/include"
	}
	postbuildcommands {
		"mkdir -p %{wks.location}/sysroot/usr/lib",
		"cp %{cfg.buildtarget.relpath} %{wks.location}/sysroot/usr/lib"
	}

	files { "%{prj.location}/**.h",
			"%{prj.location}/**.hpp",
			"%{prj.location}/**.c",
			"%{prj.location}/**.cpp",
			"%{prj.location}/**.s" }
