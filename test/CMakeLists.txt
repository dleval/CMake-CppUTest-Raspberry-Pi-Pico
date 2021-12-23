cmake_minimum_required(VERSION 3.13)

project (UnitTest)

# Check for CppUTest and bail out if they don't have it
if(DEFINED ENV{CPPUTEST_HOME})
  message("Using CppUTest found in $ENV{CPPUTEST_HOME}")
else()
  message("CPPUTEST_HOME is not set; You must tell CMake where to find CppUTest")
  return()
endif()

enable_language(C)
enable_language(CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# include project source
include_directories(${PROJECT_SOURCE_DIR}/../inc)
include_directories(${PROJECT_SOURCE_DIR}/../inc/module)


find_package(CppUTest REQUIRED)


# build test library for module
add_library(module ../src/module/module.c)
add_library(moduleTest ./module/moduleTest.cpp)


add_executable(RunAllTests RunAllTests.cpp)

target_link_libraries(RunAllTests PRIVATE 
                      moduleTest 
                      module 
                      CppUTest CppUTestExt)

# Start UnitTest program after build
add_custom_command(
    TARGET RunAllTests POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/RunAllTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running test..."
)