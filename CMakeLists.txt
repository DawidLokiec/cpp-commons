cmake_minimum_required(VERSION 3.26.1)
project(cpp-commons LANGUAGES CXX VERSION 1.0.0)

add_library(${PROJECT_NAME}
        src/text_file_reading.cpp
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC include/)
# A CMake pattern to have headers that are not seen by the client of this library.
# So headers which not have to be visible for client-code should be placed in src/
target_include_directories(${PROJECT_NAME} PRIVATE src)

if (MSVC)
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /EHsc /std:c++20)
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
        test/language_test.cpp
        test/math_test.cpp
        test/text_file_reading_test.cpp)

if (MSVC)
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME}-unit-tests PRIVATE /EHsc /std:c++20)
else ()
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # lots of warnings and all warnings as errors
    target_compile_options(${PROJECT_NAME}-unit-tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()

target_link_libraries(${PROJECT_NAME}-unit-tests gtest_main ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}-unit-tests PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set(TEST_RESOURCES_FOLDER_PATH "${PROJECT_SOURCE_DIR}/test/res/")
configure_file(config.h.in config.h @ONLY)
