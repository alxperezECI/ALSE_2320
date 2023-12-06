cmake_minimum_required( VERSION 3.1 )
project( pong )

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

add_executable( ${PROJECT_NAME} main.cpp pong_window.h pong_window.cpp pong_window.ui )
target_link_libraries ( ${PROJECT_NAME} Qt5::Core Qt5::Widgets )
