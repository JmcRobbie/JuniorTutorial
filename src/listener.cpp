#include "ros/ros.h"
#include "std_msgs/Int16.h"

class ListenerClass {
  
  public:
    int num1, num2, result = 0;
  
};

void topicCallback(const std_msgs::Int16::ConstPtr& msg, int &num)
{
  ROS_INFO("I heard: [%d] on topic", msg->data);
  num = msg->data;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
  ListenerClass l;

  int num1, num2 = 0;
  
  ros::Subscriber sub1 = n.subscribe("topic1", 1000, boost::bind(topicCallback, _1, &num1));
  ros::Subscriber sub2 = n.subscribe("topic2", 1000, boost::bind(topicCallback, _1, &num2));

  ros::spin();

  return 0;
}
