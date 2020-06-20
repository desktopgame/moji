cmake_minimum_required(VERSION 3.16)
project(macro_test C)

add_executable(main main.c)
target_include_directories(
    main
    PRIVATE
    "${MOJI_INCLUDE_DIR}"
)
target_link_directories(
    main
    PRIVATE
    "${MOJI_LIBRARY_DIR}"
)
target_link_libraries(
    main
    PRIVATE
    "${MOJI_LIBRARIES}"
)