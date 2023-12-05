cmake_minimum_required(VERSION 3.10)

project(lectura)
add_executable(${PROJECT_NAME} "lec.cpp" )
target_link_libraries (${PROJECT_NAME} sqlite3 )


