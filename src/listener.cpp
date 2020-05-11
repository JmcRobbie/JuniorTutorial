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

int selectNum(int num1, int num2)
{
  int small, large, result = 0;
  
  /* Find which number is larger */
  if(num1 == num2)
  {
    ROS_INFO("Both equal, selected %d", num1);
    return num1;
  }
  else if(num1 < num2)
  {
    small = num1;
    large = num2;
  }
  else
  {
    large = num1;
    small = num2;
  }
  
  /* Check for primes */
  if(isPrime(small))
  {
    if(isPrime(large))
    {
      ROS_INFO("Both prime, selected %d", large);
      return large;
    }
    else
    {
    ROS_INFO("Smaller is prime, selected %d", small);
    return small;
    }
  }
  else
  {
     ROS_INFO("No primes, selected %d", small);
    return large;
  }
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  int num1, num2, result = 0;
  
  ros::Subscriber sub1 = n.subscribe<std_msgs::Int32>(argv[1], 1000, boost::bind(callback, _1, &num1, argv[1]));
  ros::Subscriber sub2 = n.subscribe<std_msgs::Int32>(argv[2], 1000, boost::bind(callback, _1, &num2, argv[2]));
  
  if(num1 == 0 || num2 == 0)
    return EXIT_FAILURE;
  
  result = selectNum(num1, num2);
  
  if(result == 0)
    return EXIT_FAILURE;
  
  ros::spin();

  return 0;
}
