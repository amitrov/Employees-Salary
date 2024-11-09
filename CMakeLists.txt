# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(EmployeeSalaryProgram C)

# Set the C standard to C99 for compatibility
set(CMAKE_C_STANDARD 99)

# Add the executable
add_executable(employee_salary employees.c)

# Force GCC compiler (only if needed, if c89-gcc is causing issues)
set(CMAKE_C_COMPILER /usr/bin/gcc)
