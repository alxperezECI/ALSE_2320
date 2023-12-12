cmake_minimum_required(VERSION 3.10)

project(Final_Proyecto)
add_executable(${PROJECT_NAME} "Hum.cpp" "Hum.h" "Lluvia.cpp" "Lluvia.h" "Luz.cpp"
    "Luz.h" "Temp.cpp" "Temp.h" "Vel.cpp" "Vel.h" "Viento.cpp" "Viento.h" "Sensor.h" "Sensor.cpp" "main.cpp")
target_link_libraries (${PROJECT_NAME} sqlite3 )
