cmake_minimum_required(VERSION 3.27)
project(untitled)

set(OpenCV_DIR ~/CLionProjects/ImageToAsciiConverter/opencv/build)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        imageConverterPackage/ImageConverter.cpp
        imageConverterPackage/ImageConverter.h
        userImageControllerPackage/UserImageController.h
        userImageControllerPackage/UserImageController.cpp)

target_link_libraries(untitled ${OpenCV_LIBS})