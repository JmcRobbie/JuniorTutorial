cmake_minimum_required(VERSION 2.8.3)
project(JuniorTutorial)

# Dependencies
find_package(catkin REQUIRED COMPONENTS
   roscpp
   rospy
   std_msgs
)
catkin_package(CATKIN_DEPENDS
   roscpp
   rospy
   std_msgs
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker JuniorTutorial_generate_messages_cpp)
