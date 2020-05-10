#include "ros/ros.h"
#include "std_msgs/Int16.h"

class ListenerClass {
  
    int num1, num2, result = 0;
  
  public:
    void topicCallback(const std_msgs::Int16::ConstPtr& msg, int &num, std::string topic);
  
};

void ListenerClass::topicCallback(const std_msgs::Int16::ConstPtr& msg, int &num, std::string topic)
{
  ROS_INFO("I heard: [%d] on %s", msg->data, topic);
  num = msg->data; 
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
  ListenerClass l;

  ros::Subscriber sub1 = n.subscribe("topic1", 1000, boost::bind(topicCallback, _1, l::num1, "topic1"));
  ros::Subscriber sub1 = n.subscribe("topic1", 1000, boost::bind(topicCallback, _1, l::num2, "topic2"));

  ros::spin();

  return 0;
}
