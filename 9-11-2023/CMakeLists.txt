cmake_minimum_required(VERSION 2.8)

project(horas)
add_executable(horas main.cpp)
target_link_libraries (horas sqlite3 )
