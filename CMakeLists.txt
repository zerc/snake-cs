cmake_minimum_required(VERSION 3.23...3.24)

project(
    SnakeCS
    VERSION 0.1
    LANGUAGES C
)

find_package(Curses REQUIRED)

set(CMAKE_C_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(vendor/check)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)