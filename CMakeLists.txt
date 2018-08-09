
project( cppbank )

cmake_minimum_required(VERSION 2.8.12)

include_directories(${PROJECT_SOURCE_DIR}/gtest/googletest/include)
add_subdirectory(gtest)
set(RD_LIBS gtest pthread)

add_subdirectory(threadpool)
add_subdirectory(algo)

add_executable(metachain main.cpp bank.cpp random.hpp)

target_link_libraries(metachain tp algo ${RD_LIBS})