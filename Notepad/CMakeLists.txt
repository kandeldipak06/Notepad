#
# /src/CMakeLists.txt --
#

cmake_minimum_required(VERSION 3.1.0)

include_directories(${PROJECT_BINARY_DIR}/NotePad)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

# Populate a CMake variable with the sources
set(Notepad_SRC
    main.cpp 
    mainwindow.cpp
    mainwindow.ui
    Resources.qrc   
)

# Tell CMake to create the helloworld executable
add_executable(notepad ${Notepad_SRC})


# Use the Widgets module from Qt 5
target_link_libraries(notepad Qt5::Widgets)
target_link_libraries(notepad Qt5::PrintSupport)
