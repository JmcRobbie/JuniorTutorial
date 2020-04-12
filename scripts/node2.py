#! /usr/bin/env python


import rospy
from std_msgs.msg import Int16 
import random
def node2():
    pub = rospy.Publisher('Topic2',Int16,queue_size=10)
    rospy.init_node('node2', anonymous=True)
    rate = rospy.Rate(1) # 1hz
    while not rospy.is_shutdown():
        random_int = random.randint(1,1000)
        rospy.loginfo(random_int)
        pub.publish(random_int)
        rate.sleep()

if __name__ == '__main__':
    try:
        node2()
    except rospy.ROSInterruptException:
        pass

