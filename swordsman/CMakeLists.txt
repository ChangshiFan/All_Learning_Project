cmake_minimum_required(VERSION 3.5.0)
PROJECT(swordsman)
ADD_COMPILE_OPTIONS(-std=c++11)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## include
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(usr/local/include)
#INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

## src
AUX_SOURCE_DIRECTORY(src SRC_DIR)

SET(DEMO_SRC ${PROJECT_SOURCE_DIR}/src/main.cpp)

ADD_EXECUTABLE(swordsman ${DEMO_SRC} ${SRC_DIR})

TARGET_LINK_LIBRARIES(swordsman pthread)

#LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

#TARGET_LINK_LIBRARIES(string_class opencv_core opencv_videoio opencv_highgui opencv_imgproc)
