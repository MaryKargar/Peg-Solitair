cmake_minimum_required(VERSION 3.29)
project(PegSolitaire)

# Set output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared or static libraries
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Add the executable and source files
add_executable(peg_solitaire main.cpp peg_solitaire.cpp)

# Set the C++ standard
target_compile_features(peg_solitaire PRIVATE cxx_std_17)

# Static linking for the executable
set(CMAKE_EXE_LINKER_FLAGS "-static")