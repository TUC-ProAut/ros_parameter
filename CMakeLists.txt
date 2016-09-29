cmake_minimum_required(VERSION 2.8.3)
project(parameter_pa)

# cmake_modules for using "Eigen"-library
#   But hydro can't handle it directly
#   therefore it is only mentioned in the "package.xml" !
find_package(catkin REQUIRED COMPONENTS
#   cmake_modules
  roscpp
  roslib
)

catkin_package(
  INCLUDE_DIRS
    include

  CATKIN_DEPENDS
#     cmake_modules
    roscpp
    roslib

  LIBRARIES
    ${PROJECT_NAME}
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
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
