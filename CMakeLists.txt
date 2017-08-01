cmake_minimum_required(VERSION 2.8.3)
project(parameter_pa)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  roscpp
  roslib
)

find_package(Eigen3 REQUIRED)

catkin_package(
  INCLUDE_DIRS
    include

  CATKIN_DEPENDS
    cmake_modules
    roscpp
    roslib

  LIBRARIES
    ${PROJECT_NAME}
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/${PROJECT_NAME}_ros.cpp
)
add_dependencies(${PROJECT_NAME}
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

## Install ##
install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
