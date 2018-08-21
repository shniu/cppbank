
aux_source_directory(. IO_SRC)

# add_subdirectory(tinyhttp)

add_library(fluent ${IO_SRC} echo_client.cpp echo_server.cpp)
