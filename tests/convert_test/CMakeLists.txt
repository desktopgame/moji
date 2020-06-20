cmake_minimum_required(VERSION 3.16)
project(convert_test C)

add_executable(convert_test main.c)
target_include_directories(
    convert_test
    PRIVATE
    "${MOJI_INCLUDE_DIR}"
)
target_link_directories(
    convert_test
    PRIVATE
    "${MOJI_LIBRARY_DIR}"
)
target_link_libraries(
    convert_test
    PRIVATE
    "${MOJI_LIBRARIES}"
)