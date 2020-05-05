#include "ros/ros.h"
#include "std_msgs/Int16.h"

void topic1Callback(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, argv[1]);
}

void topic2Callback(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, argv[2]);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe(argv[1], 1000, topic1Callback);
  ros::Subscriber sub2 = n.subscribe(argv[2], 1000, topic2Callback);

  ros::spin();

  return 0;
}
