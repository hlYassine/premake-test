solution "solTest"
	configurations { "debug", "release" }
	language "C++"
	includedirs { "../src", "../libs/includes" }
	location "solution"
	libdirs { "../libs" }

configuration "debug"
	defines { "MY_DEBUG" }
	flags { "Symbols" }
	targetdir "../bin/debug"
	objdir ("../bin/debug")
	targetsuffix "_d"

configuration "release"
	targetdir "../bin/release"
	objdir ("../bin/release")
	targetsuffix "_r"


	project "projTest"
		kind "ConsoleApp"
		files { "../src/*.h", "../src/*.cpp" }
         	links { "SDL2" , "SDL2main" }
