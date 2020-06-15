cmake_minimum_required(VERSION 3.12...3.16)

project(Shapes
    VERSION 0.1
    DESCRIPTION "Shapes using bad physics"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.5.1
)
FetchContent_MakeAvailable(sfml)

set(SFML_INCLUDE_DIR ${sfml_SOURCE_DIR}/include)
set(SFML_LIBRARIES sfml-system sfml-graphics)

file(GLOB_RECURSE PUBLIC_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Project4/include/*.h*")
file(GLOB_RECURSE PRIVATE_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Project4/src/*.[hc]*")

#set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/modern/lib.hpp")
list(APPEND BOTH_LISTS ${PRIVATE_LIST})
list(APPEND BOTH_LISTS ${PUBLIC_LIST})


add_executable(shapes ${BOTH_LISTS} ${SFML_INCLUDE_DIR})

target_include_directories(shapes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Project4/include)
target_link_libraries(shapes PRIVATE ${SFML_LIBRARIES})

#message(STATUS "SFML BUILD DIR: ${sfml_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

add_custom_command(TARGET shapes POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_directory  # which executes "cmake - E copy_if_different..."
        "${sfml_BINARY_DIR}/lib/"      # <--this is in-file
        $<TARGET_FILE_DIR:shapes>)                 # <--this is out-file path
