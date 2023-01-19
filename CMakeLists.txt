cmake_minimum_required(VERSION 3.25.1)
project(cpp-commons LANGUAGES CXX VERSION 1.0.0)

add_library(${PROJECT_NAME}
        src/text_file_reading.cpp
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC include/)
# A CMake pattern to have headers that are not seen by the consumers of this library.
# So headers which not have to be visible for consumers should be placed in src/
target_include_directories(${PROJECT_NAME} PRIVATE src)

if (MSVC)
    # PUBLIC = use this compile options also while compiling the project simulation-engine
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME} PUBLIC /W4 /WX)
else ()
    # PUBLIC = use this compile options also while compiling the project simulation-engine
    # lots of warnings and all warnings as errors
    target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -pedantic -Werror)
endif ()