cmake_minimum_required(VERSION 3.16)
project(minipad C)

#
# load extensions
#
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckSymbolExists)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_library(moji lib/moji/moji.c)
target_include_directories(
    moji
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

CHECK_INCLUDE_FILE(unistd.h HAVE_UNISTD)
CHECK_INCLUDE_FILE(windows.h HAVE_WINDOWS)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/moji/config.in ${CMAKE_CURRENT_SOURCE_DIR}/include/moji/config.h)


#
# test suite
#
set(MOJI_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(MOJI_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(MOJI_LIBRARIES "moji")
mark_as_advanced(MOJI_INCLUDE_DIR)
mark_as_advanced(MOJI_LIBRARY_DIR)
mark_as_advanced(MOJI_LIBRARIES)

enable_testing()
add_subdirectory(tests/macro_test)
add_test(macro_test tests/macro_test/macro_test)

add_subdirectory(tests/count_test)
add_test(count_test tests/count_test/count_test)

add_subdirectory(tests/convert_test)
add_test(convert_test tests/convert_test/convert_test)