#include <ros/ros.h>
#include <stdlib.h>
#include "std_msgs/Int32.h"



int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_node1");
    ros::NodeHandle nh;

    //advertise to topic1
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic1", 1000);
    //random number seed
    srand(time(0));
    ros::Rate rate(2);

    
    while (ros::ok())
    {
        std_msgs::Int32 num;
        //calculate random number between 1 and 1000 to publish
        num.data = rand() % 1000 + 1;
        //ROS_INFO("topic 1: %d", num.data);
        pub.publish(num);
        //callback and return immediately
        ros::spinOnce();
        //thread sleep
        rate.sleep();

    }
}