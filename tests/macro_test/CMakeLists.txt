cmake_minimum_required(VERSION 3.16)
project(macro_test C)

add_executable(macro_test main.c)
target_include_directories(
    macro_test
    PRIVATE
    "${MOJI_INCLUDE_DIR}"
)
target_link_directories(
    macro_test
    PRIVATE
    "${MOJI_LIBRARY_DIR}"
)
target_link_libraries(
    macro_test
    PRIVATE
    "${MOJI_LIBRARIES}"
)