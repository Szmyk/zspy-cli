cmake_minimum_required(VERSION 3.12.1)

project(zspy-cli CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES
	"include/*.h"
	"src/*.cpp"
)

include_directories(lib/rang)
include_directories(lib/args)

include_directories(zspy-cli PUBLIC include)

add_executable(zspy-cli ${SOURCES})
