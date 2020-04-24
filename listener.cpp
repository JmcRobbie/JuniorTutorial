#include <ros/ros.h>
#include "std_msgs/Int32.h"

//Class to help access both the callback values
class NumSelector {

    public:
        int first_topic_num;
        int second_topic_num;
    
    //Callback for the first topic
     void topic1CallBack(const std_msgs::Int32::ConstPtr& num) {
        first_topic_num = num->data;
        ROS_INFO("Topic 1 said: %d",first_topic_num);
    }
    //callback for the second topic
    void topic2CallBack(const std_msgs::Int32::ConstPtr& num) {
        second_topic_num = num->data;
        ROS_INFO("Topic 2 said: %d", second_topic_num);
    }
    //helper function to check if a number is prime
    bool isPrime(int num) {
        for (int i = 2; i <= num/2; i++) {
            if (num % i == 0)
            {
                return false;
            }
            
        }

        return true;
        
    }
    //Logic to calculate the correct number to output
    int process_nums() {
        if (first_topic_num > second_topic_num) {
            if (isPrime(first_topic_num) && isPrime(second_topic_num))
            {
                return first_topic_num;
            }

            else if (!isPrime(first_topic_num) && isPrime(second_topic_num))
            {
                return second_topic_num;
            }
            
            else
            {
                return first_topic_num;
            }     
        }

        else if (second_topic_num > first_topic_num)
        {
            if (isPrime(first_topic_num) && isPrime(second_topic_num))
            {
                return second_topic_num;
            }

            else if (!isPrime(second_topic_num) && isPrime(first_topic_num))
            {
                return first_topic_num;
            }
            
            else
            {
                return second_topic_num;
            }  
        }
               
    }
};

int main(int argc, char **argv) {

    NumSelector numSelector;
    //initiate
    ros::init(argc, argv, "listener");

    ros::NodeHandle nh;

    ros::Subscriber sub1 = nh.subscribe("topic1", 1000, &NumSelector::topic1CallBack, &numSelector);
    ros::Subscriber sub2 = nh.subscribe("topic2", 1000, &NumSelector::topic2CallBack, &numSelector);
    ros::Rate loop_rate(2);
    //loop through and calculate result each time
    while (ros::ok()) {
        //non-blocking call version of spin()
        ros::spinOnce();
        int result;
        result = numSelector.process_nums();
        
        ROS_INFO("Result: %d", result);
        
        loop_rate.sleep();
    }

    return 0;

    
}