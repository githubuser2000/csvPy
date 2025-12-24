cmake_minimum_required(VERSION 3.16)
project(econ678utf LANGUAGES CXX)

# C++-Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# UTF-8
add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

# Binary in <project>/bin erzeugen
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Executable
add_executable(econ678utf
    src/main.cpp
    src/text.cpp
    src/rational.cpp
    src/space.cpp
)

# Includes
target_include_directories(econ678utf PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Zielordner außerhalb des Projekts
set(EXTERNAL_BIN_DIR $ENV{HOME}/myRepos/csvPy/econs/bin)

# Nach Build automatisch dorthin kopieren
add_custom_command(TARGET econ678utf POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${EXTERNAL_BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:econ678utf>
        ${EXTERNAL_BIN_DIR}/
    COMMENT "Copying econ678utf -> ${EXTERNAL_BIN_DIR}"
)
