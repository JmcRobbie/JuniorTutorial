#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <math.h>

void callback(const std_msgs::Int32ConstPtr& msg, int* pNum, char* topic)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, topic);
  *pNum =  msg->data;
}

bool isPrime(int num)
{
  if(num == 1)
    return false;
  
  for(int i = 2; i <= sqrt(num); i++)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}

short int selectNum(int* pNum1, int* pNum2)
{
  int result = 0;
  return result;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  int num1, num2 = 0;
  
  ros::Subscriber sub1 = n.subscribe<std_msgs::Int32>(argv[1], 1000, boost::bind(callback, _1, &num1, argv[1]));
  ros::Subscriber sub2 = n.subscribe<std_msgs::Int32>(argv[2], 1000, boost::bind(callback, _1, &num2, argv[2]));
  
  ros::spin();

  return 0;
}
