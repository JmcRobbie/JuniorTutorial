#!/usr/bin/env python

import rospy, random
from std_msgs.msg import Int32

def publisher():
    pub = rospy.Publisher('str_publish1', Int32, queue_size=10)
    rospy.init_node("publisher1", anonymous=True)
    rate = rospy.Rate(1)
    msg_to_publish = Int32()
    num = 0

    while (not rospy.is_shutdown() and (num < 1000)):
        num = random.randint(1, 1000)

        msg_to_publish.data = num
        pub.publish(msg_to_publish)

        rate.sleep()

if __name__=="__main__":
    publisher()
