cmake_minimum_required(VERSION 3.5.0)
PROJECT(sort)
ADD_COMPILE_OPTIONS(-std=c++14)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#FIND_PACKAGE(OpenCV)

## include
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(usr/local/include)
#INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

## src
AUX_SOURCE_DIRECTORY(src SRC_DIR)
SET(MAIN_DIR ${PROJECT_SOURCE_DIR}/src/main.cpp)

#add_library(sortlib ${SRC_DIR})
#target_link_libraries(sortlib)


ADD_EXECUTABLE(sort ${SRC_DIR} ${MAIN_DIR})

#LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

#TARGET_LINK_LIBRARIES(string_class opencv_core opencv_videoio opencv_highgui opencv_imgproc)
