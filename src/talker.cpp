#include "ros/ros.h"
#include "std_msgs/Int16.h"

#define FREQ 1
#define MIN 1
#define MAX 1000

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  
  ros::NodeHandle n;

  ros::Publisher talker_pub = n.advertise<std_msgs::Int16>(topic, 1000);

  ros::Rate loop_rate(FREQ);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int16 msg;
    
    msg.data = rand() % (MAX - MIN) + MIN;

    ROS_INFO("%s: %d", topic, msg.data);

    talker_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
