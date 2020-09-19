#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16
from random import randint


def nodePublish1():
	pub = rospy.Publisher('pub1', Int16, queue_size = 10)
	rospy.init_node('nodePublish1', anonymous = True)
	rate = rospy.Rate(1) # rate of display
	while not rospy.is_shutdown():
		number = randint(1, 1000) # random number generator between limits
		rospy.loginfo(number)
		pub.publish(number)
		rate.sleep()

if __name__ == '__main__':
	try: 
		nodePublish1() # generating the two nodes via the argument variables
	except rospy.ROSInterruptException:
		pass