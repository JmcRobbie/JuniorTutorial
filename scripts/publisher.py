#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16
from random import randint
import sys

def publisher(node_num):
	pub = rospy.Publisher('pub%s' %(node_num), Int16, queue_size = 10)
	rospy.init_node('publisher', anonymous = True)
	rate = rospy.Rate(1)
	while not rospy.is_shutdown():
		#generate random number
		num = randint(1, 1000)
		rospy.loginfo(num)
		pub.publish(num)
		rate.sleep()

if __name__ == '__main__':
	try: 
		publisher(sys.argv[1])
	except rospy.ROSInterruptException:
		pass