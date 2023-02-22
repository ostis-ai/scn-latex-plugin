set(GRAMMAR_DIR "${CMAKE_CURRENT_LIST_DIR}/grammar")
set(TRANSLATOR_DIR "${CMAKE_CURRENT_LIST_DIR}/translator")

add_custom_command(OUTPUT
    "${TRANSLATOR_DIR}/SCnTexLexer.cpp"
    "${TRANSLATOR_DIR}/SCnTexLexer.h"
    "${TRANSLATOR_DIR}/SCnTexParser.cpp"
    "${TRANSLATOR_DIR}/SCnTexParser.h"
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR_DIR}/antlr-4.7.1-complete.jar"
        ${GRAMMAR_DIR}/SCnTex.g4 -no-listener -package translator
    WORKING_DIRECTORY "${TRANSLATOR_DIR}"
    DEPENDS ${GRAMMAR_DIR}/SCnTex.g4
)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)

add_executable(macros-translator
    ${SOURCES}
    ${Boost_INCLUDE_DIRS}
    "${ANTLR_DIR}/runtime/src"
)

target_include_directories(macros-translator PRIVATE ${ANTLR_DIR}/runtime/src)
target_link_libraries(macros-translator antlr4_static ${Boost_LIBRARIES} ${LIBCURL_LIBRARIES})

add_dependencies(macros-translator antlr4_static)
