#include "ros/ros.h"
#include "std_msgs/Int16.h"

void callback(const std_msgs::Int16ConstPtr& msg, short int* pNum, char* topic)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, topic);
  *pNum =  msg->data;
}

short int selectNum(short int* pNum1, short int* pNum2)
{
  short int result = 0;
  return result;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  short int num1, num2 = 0;
  
  ros::Subscriber sub1 = n.subscribe<std_msgs::Int16>(argv[1], 1000, boost::bind(callback, _1, &num1, argv[1]));
  ros::Subscriber sub2 = n.subscribe<std_msgs::Int16>(argv[2], 1000, boost::bind(callback, _1, &num2, argv[2]));
  
  ros::spin();

  return 0;
}
