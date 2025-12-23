cmake_minimum_required(VERSION 3.16)
project(econ567 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executable nach bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Bibliothek
add_library(econlib STATIC
    econ.cpp
)

target_include_directories(econlib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Executable
add_executable(econ567
    main.cpp
)

target_link_libraries(econ567
    PRIVATE econlib
)
