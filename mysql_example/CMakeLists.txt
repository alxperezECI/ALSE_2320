cmake_minimum_required(VERSION 2.8)

project(mysqldb_testing)
add_executable(${PROJECT_NAME} "mysqldb_test.cpp" )
target_link_libraries (${PROJECT_NAME} mysqlclient )

