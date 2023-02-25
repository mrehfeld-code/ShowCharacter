cmake_minimum_required(VERSION 3.20)

project(ShowCharacter LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

if(MSVC)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
endif()

set(SOURCE_FILES "src/main.cpp")

add_subdirectory("external/SDL")
add_subdirectory("external/SDL_image")

add_executable(ShowCharacter ${SOURCE_FILES})

target_include_directories(ShowCharacter PUBLIC "external/SDL/include")
target_link_libraries(ShowCharacter PUBLIC SDL3-shared)

target_include_directories(ShowCharacter PUBLIC "external/SDL_image/include")
target_link_libraries(ShowCharacter PUBLIC SDL3_image)

if(MSVC)
	set_target_properties(ShowCharacter PROPERTIES VS_DEBUGGER_WORKING_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG})
endif()
