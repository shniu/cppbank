
project( fluentcpp )

cmake_minimum_required(VERSION 2.8.12)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


include_directories(${PROJECT_SOURCE_DIR}/gtest/googletest/include)
add_subdirectory(gtest)
set(RD_LIBS gtest pthread)

add_subdirectory(algo)
add_subdirectory(src)

add_executable(metachain main.cpp bank.cpp random.hpp)

target_link_libraries(metachain algo fluent ${RD_LIBS})
