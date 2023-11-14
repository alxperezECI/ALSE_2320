cmake_minimum_required( VERSION 3.10 )
project( ejercicio_horas_extra )
add_executable ( ${PROJECT_NAME} main.cpp)
target_link_libraries(ejercicio_horas_extra PRIVATE sqlite3)
