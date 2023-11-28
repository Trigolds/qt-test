# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

# Tell CMake to create the executable
add_executable(Test002 main.cpp header.hpp header.cpp)

# Link the Qt libraries to your executable
target_link_libraries(Test002 Qt5::Core Qt5::Widgets Qt5::Gui Qt5::OpenGL)
