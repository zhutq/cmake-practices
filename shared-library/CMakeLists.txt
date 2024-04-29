cmake_minimum_required( VERSION 3.14 )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(echo LANGUAGES CXX VERSION 1.0.0)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(CMAKE_DEBUG_POSTFIX d) # 必须放在 add_library 前面
set(LIBRARY_NAME echo)
add_library(${LIBRARY_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/echo.cpp
)

target_compile_options(${LIBRARY_NAME} PRIVATE /Zi)
target_link_options(${LIBRARY_NAME} PRIVATE /DEBUG)

# install 命令中的 FILE_SET 需要使用
# TODO: 如何修改文件夹名?
target_sources(${LIBRARY_NAME} PUBLIC FILE_SET HEADERS FILES
    ${CMAKE_CURRENT_LIST_DIR}/echo/echo.h
    ${CMAKE_CURRENT_LIST_DIR}/echo/exports.h)

target_include_directories(${LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/echo)
target_compile_definitions(${LIBRARY_NAME} PRIVATE ECHO_COMPILE_LIBRARY)

install(TARGETS ${LIBRARY_NAME}
    EXPORT echoConfig
    CONFIGURATIONS Debug Release
    RUNTIME COMPONENT Runtime
    LIBRARY COMPONENT Runtime
    ARCHIVE COMPONENT Development
    FILE_SET HEADERS COMPONENT Development
)
install(FILES $<TARGET_PDB_FILE:${LIBRARY_NAME}> DESTINATION bin OPTIONAL)
export(TARGETS
        ${LIBRARY_NAME}
    NAMESPACE echo::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/echoConfig.cmake"
)
install(EXPORT
    echoConfig
    DESTINATION "lib/cmake/echo"
    NAMESPACE echo::
)
