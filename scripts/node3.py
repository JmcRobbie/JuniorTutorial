#! /usr/bin/env python


import rospy
from std_msgs.msg import Int16 
import random

class Two_Integers:
    def __init__(self):
        self.int1 = 0
        self.int2 = 0

    def topic1_callback(self,data):
        self.int1 = data.data
    def topic2_callback(self,data):
        self.int2 = data.data
        self.print_int()


    def print_int(self):
        if self.int1 and self.int2:
            rospy.loginfo("Integers: "+ str(self.int1)+ ", "+str(self.int2))
            smaller,larger = min(self.int1,self.int2),max(self.int1,self.int2)
            if is_prime(smaller) and not is_prime(larger):
                rospy.loginfo("The integer printed is %s", str(smaller))
            else:
                rospy.loginfo("The integer printed is %s",str(larger))



def is_prime(num):
    for i in range(2,num):
        if num%i == 0:
            return False
    return True

def callback(data):
    rospy.loginfo(data)

def node3():
    rospy.init_node('node3', anonymous=True)
    
    two_ints = Two_Integers()

    rospy.Subscriber('Topic1',Int16, two_ints.topic1_callback)
    rospy.Subscriber('Topic2',Int16, two_ints.topic2_callback)

    rospy.spin()

if __name__ == '__main__':
    node3()

