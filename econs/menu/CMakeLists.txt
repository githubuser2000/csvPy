cmake_minimum_required(VERSION 3.16)

project(econ49 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Output in <project>/bin ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# Standardmäßig USE_NCURSES aktivieren
option(USE_NCURSES "Enable ncurses TUI" ON)

add_executable(menu
    src/mode_text.cpp
    ../567/src/main.cpp
    ../678/en/src/main.cpp
    ../678/de/src/main.cpp
    ../econ567/src/main.cpp
    ../567/include/math_utils.h
)

# Header-Verzeichnisse hinzufügen
target_include_directories(menu PRIVATE
    ../567/include
    ../678/en/include
    ../678/de/include
    ../econ567/include
)

# --- Includes ---
include_directories(${PROJECT_SOURCE_DIR}/include)

# --- Quellen ---
add_executable(econ49
    src/main.cpp
    src/bitmask.cpp
    src/mode_text.cpp
    src/mode_toggle.cpp
    src/mode_ncurses.cpp
)

# --- Optional: ncurses Mode ---
if (USE_NCURSES)
    target_compile_definitions(econ49 PRIVATE USE_NCURSES)
    target_link_libraries(econ49 ncurses)
endif()

# --- Zielpfad für Deployment ---
set(DEPLOY_DIR $ENV{HOME}/myRepos/csvPy/econs/bin)

# --- Beim Build zusätzlich dorthin kopieren ---
add_custom_command(TARGET econ49 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:econ49>
        ${DEPLOY_DIR}
    COMMENT "Kopiere Binary nach ${DEPLOY_DIR}"
)
