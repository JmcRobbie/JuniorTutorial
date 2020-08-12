#!/usr/bin/env python

import rospy, math
from std_msgs.msg import Int32

num1 = 0

def is_prime(num):
    for i in range(2, int(math.sqrt(num)+1)):
        if (num%i==0):
            return 0
    return 1


def callback_function_one(message):
    global num1
    num1 = message.data

def callback_function_two(message):
    num2 = message.data

    if is_prime(min(num1, num2)):
        if is_prime(max(num1, num2)):
            rospy.loginfo("%d"%max(num1, num2))
        else:
            rospy.loginfo("%d"%min(num1, num2))
    else:
        rospy.loginfo("%d"%max(num1, num2))



def subscriber():
    rospy.init_node('subscriber', anonymous=True)

    sub1 = rospy.Subscriber("str_publish1", Int32, callback_function_one)
    sub2 = rospy.Subscriber("str_publish2", Int32, callback_function_two)

    rospy.spin()

if __name__=="__main__":
    subscriber()
