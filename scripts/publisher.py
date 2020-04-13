#! /usr/bin/env python


import rospy
from std_msgs.msg import Int16
import random
import sys


def publisher():
    pub = rospy.Publisher('Topic%s' %(sys.argv[1]),Int16,queue_size=10)
    rospy.init_node('pub%s' %(sys.argv[1]), anonymous=True)
    rate = rospy.Rate(1) # 1hz
    while not rospy.is_shutdown():
        random_int = random.randint(1,1000) 
        rospy.loginfo(random_int)
        pub.publish(random_int)
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
