cmake_minimum_required(VERSION 2.8.3)
project(parameter_pa)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  roscpp
  roslib

  message_generation
)

find_package(Eigen3 REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

add_service_files(
  FILES
    ParameterPaString.srv
)
generate_messages(
  DEPENDENCIES
)

catkin_package(
  INCLUDE_DIRS
    include

  CATKIN_DEPENDS
    cmake_modules
    roscpp
    roslib

    message_runtime

  LIBRARIES
    ${PROJECT_NAME}
)

### exported libraries
add_library(${PROJECT_NAME}
  src/${PROJECT_NAME}_ros.cpp
)
add_dependencies(${PROJECT_NAME}
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

### simple node
add_executable(${PROJECT_NAME}_node
  src/${PROJECT_NAME}_node.cpp
)
add_dependencies(${PROJECT_NAME}_node
  ${catkin_EXPORTED_TARGETS}
  ${PROJECT_NAME}
  ${PROJECT_NAME}_generate_messages_cpp
  ${PROJECT_NAME}_gencpp
)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

## Install ##
install(
  TARGETS
    ${PROJECT_NAME}
    ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  FILES_MATCHING PATTERN "*.launch"
)
