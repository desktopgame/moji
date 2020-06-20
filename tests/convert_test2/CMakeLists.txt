cmake_minimum_required(VERSION 3.16)
project(convert_test2 C)

add_executable(convert_test2 main.c)
target_include_directories(
    convert_test2
    PRIVATE
    "${MOJI_INCLUDE_DIR}"
)
target_link_directories(
    convert_test2
    PRIVATE
    "${MOJI_LIBRARY_DIR}"
)
target_link_libraries(
    convert_test2
    PRIVATE
    "${MOJI_LIBRARIES}"
)