cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled "Balu tvarkykle.cpp" Student.h Student.cpp StudentFileProcessor.cpp StudentFileProcessor.h GeneralUtils.cpp GeneralUtils.h StudentConsoleInputProcessor.cpp StudentConsoleInputProcessor.h StudentFIleGenerator.cpp StudentFIleGenerator.h)
