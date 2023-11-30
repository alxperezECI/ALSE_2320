cmake_minimum_required(VERSION 3.10)

project(proyecto_final)
add_executable(proyecto_final main.cpp sensor.h sensor.cpp dr_viento.cpp dr_viento.h humedad.cpp humedad.h
int_luz.cpp int_luz.h precipitacion.h precipitacion.cpp temperatura.h temperatura.cpp velocidad.h velocidad.cpp)
target_link_libraries (proyecto_final sqlite3 )
