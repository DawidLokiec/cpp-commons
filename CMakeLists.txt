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
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else ()
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # lots of warnings and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()

# Enable testing
enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Unit tests as an executable of this library
add_executable(${PROJECT_NAME}-unit-tests
        test/math_test.cpp
        )

target_link_libraries(${PROJECT_NAME}-unit-tests gtest_main ${PROJECT_NAME})
