#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>

#include <time.h>


int main(int argc, char **argv)
{
  //initialisation
  ros::init(argc, argv, "num_1");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Int32>("number_stream_1", 1000);
  ros::Rate loop_rate(5);

  srand(time(NULL));

  long num;
  int count = 0;

  //publishing loop
  while (ros::ok())
  {
    num = rand() % 1000 + 1;
   
    std_msgs::Int32 msg;
    msg.data = num;

    ROS_INFO("%d", msg.data);
    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
