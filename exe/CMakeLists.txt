cmake_minimum_required( VERSION 3.14 )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(main)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(main
    main.cpp
)

find_package(echo)
target_link_libraries(main echo::echo)

add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:main> $<TARGET_RUNTIME_DLLS:main> COMMAND_EXPAND_LISTS)
