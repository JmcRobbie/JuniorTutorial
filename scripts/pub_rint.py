#!/usr/bin/env python

# Publishes random int between 1-1000 to topic[n]
# Takes the first argument as the topic number

import rospy, random
from std_msgs.msg import Int16
import sys

def pub_rint():
    argv = rospy.myargv(argv=sys.argv)
    topic_nb = argv[1]
    debug_nb = int(argv[2]) if len(argv) > 2 else None

    pub = rospy.Publisher('topic%s' % topic_nb, Int16, queue_size=20)
    rospy.init_node('pub_rint', anonymous=True)

    if debug_nb: rospy.loginfo('Debug Mode: %d', debug_nb)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        rint = random.randint(1, 1000)
        if debug_nb:
            pub.publish(debug_nb)
        else:
            pub.publish(rint)
        rate.sleep()

if __name__ == '__main__':
    try:
        pub_rint()
    except rospy.ROSInterruptException:
        pass