#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16

integers = []

def printer(data):
	integers.append(data.data)
	rospy.loginfo("added %d", data.data)
	if len(integers) == 2:
		rospy.loginfo("%d and %d" %(integers[0], integers[1]))
		# do calculations?
		del integers[:]
		rospy.loginfo("list len is now %d", len(integers))

	if len(integers) > 2:
		rospy.loginfo("broken")


def subscriber():

	rospy.init_node('subscriber', anonymous=True)
	rospy.Subscriber('pub1', Int16, printer)
	rospy.Subscriber('pub2', Int16, printer)
	rospy.spin()

if __name__ == '__main__':
	subscriber()