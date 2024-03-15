cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)


set(LOCAL_PROJECT_NAME "flight")
set(LOCAL_PROJECT_VERSION "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Description")

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)


# Header files (relative to "include" directory)
set(
    HEADERS
    aircraft_data.h
    aircraft.h
    maths.h
)

# Source files (relative to "src" directory)
set(
    SOURCES
    aircraft_data.cpp
    aircraft.cpp
    maths.cpp
    main.cpp
)

# Project setup
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES CXX)

enable_testing()
include(CTest)

add_executable(${LOCAL_PROJECT_NAME})

list(TRANSFORM HEADERS PREPEND "include/")
list(TRANSFORM SOURCES PREPEND "src/")

# target sources and include libraries
target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${LOCAL_PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})


# output to bin
set_target_properties(${LOCAL_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
# Testing
set(
    TEST_SOURCES
    test_aircraft.cpp
)
list(TRANSFORM TEST_SOURCES PREPEND "tests/")

add_executable(
    test_${LOCAL_PROJECT_NAME}
    ${TEST_SOURCES}
)
set_target_properties(test_${LOCAL_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
target_include_directories(
    test_${LOCAL_PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    test_${LOCAL_PROJECT_NAME}
    GTest::gtest_main
)
gtest_discover_tests(
    test_${LOCAL_PROJECT_NAME}

)


