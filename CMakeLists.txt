cmake_minimum_required(VERSION 3.0.2)
project(camera_stream_publisher)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  image_transport
  cv_bridge
)

find_package(OpenCV REQUIRED)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES camera_stream_publisher
  CATKIN_DEPENDS roscpp image_transport cv_bridge
  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}

)

add_executable(${PROJECT_NAME}_node src/stream_publisher.cpp)


add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS} 
)
