cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "flight")
set(PROJECT_VERSION "0.0.1")
set(PROJECT_DESCRIPTION "Description")

# Project setup
project(
  ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  DESCRIPTION ${PROJECT_DESCRIPTION}
  LANGUAGES CXX)

# Header files (relative to "include" directory)
set(HEADERS aircraft_data.h aircraft.h maths.h)

# Source files (relative to "src" directory)

set(SOURCE_FILES aircraft_data.cpp aircraft.cpp maths.cpp)
set(SOURCES ${SOURCE_FILES} main.cpp)

list(TRANSFORM HEADERS PREPEND "include/")
list(TRANSFORM SOURCES PREPEND "src/")
list(TRANSFORM SOURCE_FILES PREPEND "src/")

enable_testing()
include(CTest)

add_executable(${PROJECT_NAME})

# target sources and include libraries
target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})

# Testing GoogleTest setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Setting testing variables
set(TEST_SOURCES test_aircraft.cpp test_maths.cpp)
list(TRANSFORM TEST_SOURCES PREPEND "tests/")

add_executable(test_${PROJECT_NAME} ${TEST_SOURCES} ${SOURCE_FILES})
target_include_directories(test_${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_${PROJECT_NAME} GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_${PROJECT_NAME})

# output to bin
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
set_target_properties(test_${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                      "bin")
