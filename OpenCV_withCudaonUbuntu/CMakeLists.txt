cmake_minimum_required(VERSION 2.8)
project ( Project_run )
find_package( OpenCV REQUIRED)
add_executable( Project_run  code.cpp)  //your cpp file name
target_link_libraries( Project_run ${OpenCV_LIBS} )
