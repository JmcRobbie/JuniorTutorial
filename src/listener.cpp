#include "ros/ros.h"
#include "std_msgs/Int16.h"

class ListenerClass {
  
  public:
    int num1, num2, result = 0;
  
};

void topic1Callback(const std_msgs::Int16ConstPtr& msg, int &num)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, "topic1");
  num = msg->data;
}

void topic2Callback(const std_msgs::Int16ConstPtr& msg, int &num)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, "topic2");
  num = msg->data;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
  ListenerClass l;

  int num1, num2 = 0;
  
  ros::Subscriber sub1 = n.subscribe<std_msgs::Int16>("topic1", 1000, boost::bind(topic1Callback, _1, &num1));
  ros::Subscriber sub2 = n.subscribe<std_msgs::Int16>("topic2", 1000, boost::bind(topic2Callback, _1, &num2));

  ros::spin();

  return 0;
}
