#!/usr/bin/env python

import rospy
import message_filters
from std_msgs.msg import Int16

# Global var to store the numbers published
pub_ints = [0, 0]

def isprime(num):
    if num == 1: return False
    for d in range(2, int(num ** 0.5) + 1):
        if num % d == 0:
            return False
    return True

# Callbacks store the numbers published in each topic
def callback1(data):
    pub_ints[0] = data.data

def callback2(data):
    pub_ints[1] = data.data

def listener():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('topic1', Int16, callback1)
    rospy.Subscriber('topic2', Int16, callback2)

    rate = rospy.Rate(10) # Listen at 10hz, the same rate as the publishers
    while not rospy.is_shutdown():
        num = max(pub_ints)
        primes = [n for n in pub_ints if isprime(n)] # find prime numbers
        if len(primes) != 0: num = max(primes) # if there are prime numbers, find the biggest of those
        # if the largest number is 0 
        # (only possible when no numbers have been published since numbers are between 1-1000) 
        # don't print anything
        if num != 0: 
            rospy.loginfo(num)
        # reset stored numbers
        pub_ints[0], pub_ints[1] = 0, 0
        
        rate.sleep()

if __name__ == '__main__':
    listener()
