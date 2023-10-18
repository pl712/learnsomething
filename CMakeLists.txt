cmake_minimum_required(VERSION 3.21)
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG)

pybind11_add_module(cppCalc prime.cpp)