cmake_minimum_required(VERSION 3.16)
project(count_test C)

add_executable(count_test main.c)
target_include_directories(
    count_test
    PRIVATE
    "${MOJI_INCLUDE_DIR}"
)
target_link_directories(
    count_test
    PRIVATE
    "${MOJI_LIBRARY_DIR}"
)
target_link_libraries(
    count_test
    PRIVATE
    "${MOJI_LIBRARIES}"
)