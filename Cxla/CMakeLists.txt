# CMakeList.txt : CMake project for Mat++, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Cxla "src/Cxla.cpp" "include/Cxla.h" "include/Vector.h")

# TODO: Add tests and install targets if needed.