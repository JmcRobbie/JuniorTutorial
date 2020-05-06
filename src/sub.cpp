#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <iostream>
#include <ostream>

long numA = -1;
long numB = -1;

void stream_1_callback(const std_msgs::Int32::ConstPtr& msg)
{
  numA = msg->data;
}

void stream_2_callback(const std_msgs::Int32::ConstPtr& msg)
{
  numB = msg->data;
}

bool checkPrime(long num)
{
  if (num < 2){
    return false;
  }

  for(int i = 2; i*i < num; i++){
    if (!(num % i)){
      return false;
    }
  }

  return true;
}

int max(long a, long b){ return a < b ? b : a;}

int min(long a, long b){ return a < b ? a : b;}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub1 = n.subscribe("number_stream_1", 1000, stream_1_callback);
  ros::Subscriber sub2 = n.subscribe("number_stream_2", 1000, stream_2_callback);

  ros::Rate loop_rate(5);

  while (ros::ok()){

    if (checkPrime(min(numA, numB)) && !checkPrime(max(numA, numB))){
      std::cout << min(numA, numB) << std::endl;
    } else if (max(numA, numB) != -1){
      std::cout << max(numA, numB) << std::endl;
    }

    ros::spinOnce();

  loop_rate.sleep();
  }

  return 0;
}
