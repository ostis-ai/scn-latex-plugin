cmake_minimum_required(VERSION 2.8)
project(scn-macros-translator)
cmake_policy(SET CMP0048 NEW)
set(TRANSLATOR_ROOT ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_CXX_STANDARD 17)

set(SC_BIN_PATH "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SC_BIN_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SC_BIN_PATH})

set(THIRDPARTY_DIR "${TRANSLATOR_ROOT}/thirdparty")
set(ANTLR_DIR "${THIRDPARTY_DIR}/antlr")

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(${ANTLR_DIR}/runtime)
add_subdirectory(${TRANSLATOR_ROOT}/src)
