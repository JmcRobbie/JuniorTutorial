#include <ros/ros.h>
#include "std_msgs/Int32.h"


class NumSelector {

    public:
        int first_topic_num;
        int second_topic_num;

     void topic1CallBack(const std_msgs::Int32::ConstPtr& num) {
        first_topic_num = num->data;
        ROS_INFO("Topic 1 said: %d",first_topic_num);
    }

    void topic2CallBack(const std_msgs::Int32::ConstPtr& num) {
        second_topic_num = num->data;
        ROS_INFO("Topic 2 said: %d", second_topic_num);
    }

    bool isPrime(int num) {
        for (int i = 2; i <= num/2; i++) {
            if (num % i == 0)
            {
                return false;
            }
            
        }

        return true;
        
    }

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
    ros::init(argc, argv, "listener");

    ros::NodeHandle nh;

    ros::Subscriber sub1 = nh.subscribe("topic1", 1000, &NumSelector::topic1CallBack, &numSelector);
    ros::Subscriber sub2 = nh.subscribe("topic2", 1000, &NumSelector::topic2CallBack, &numSelector);

    int result;
    result = numSelector.process_nums();
    ROS_INFO("Result: %d", result);
    ros::spin();

    return 0;
}