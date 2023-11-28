cmake_minimum_required(VERSION 3.10)

project(qt_example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package( Eigen3 REQUIRED )
add_executable(qt_example
    main.cpp
    vantana.cpp
    vantana.h
    vantana.ui
    divi_diag.cpp
    divi_diag.h
    divi_diag.ui
)

target_link_libraries(qt_example PRIVATE Qt5::Widgets)
