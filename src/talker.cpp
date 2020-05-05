#include "ros/ros.h"
#include "std_msgs/Int16.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  
  ros::NodeHandle n;

  ros::Publisher talker_pub = n.advertise<std_msgs::Int16>("nums", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int16 msg;

    std::int16 a;
    msg.data = a;

    ROS_INFO("%d", msg.data);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
