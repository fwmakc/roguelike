cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)

set(LOCAL_PROJECT_NAME        "Project")
set(LOCAL_PROJECT_VERSION     "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Description")

# Header files (relative to "include" directory)
file(GLOB_RECURSE HEADERS "includes/*.h")

# Source files (relative to "src" directory)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Compiler definitions
set(DEFINES

)

# Compiler options
set(OPTIONS

)

# Project setup
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES C CXX)

add_executable(${LOCAL_PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${LOCAL_PROJECT_NAME} pdcurses_wincon winmm)

target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

set_target_properties(${LOCAL_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
