#include "ros/ros.h"
#include "std_msgs/Int16.h"

void nums1Callback(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d] on nums1", msg->data);
}

void nums2Callback(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d] on nums2", msg->data);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe(argv[1], 1000, nums1Callback);
  ros::Subscriber sub2 = n.subscribe(argv[2], 1000, nums2Callback);

  ros::spin();

  return 0;
}
