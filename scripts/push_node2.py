#!/usr/bin/env python
# Author: Peter Stulpner, pstulpner@student.unimelb.edu.au
# Script creates a second node to publish a random integer to the topic second_num
import rospy
from std_msgs.msg import String
from random import seed
from random import randint

def int_generator(i, j):
	'''Function returns a random integer between i and j'''
	return randint(i, j)

def main():
	# Initialise the publisher
	pub = rospy.Publisher("second_num", String, queue_size=10)

	# Initialise the node
	rospy.init_node("push_node2", anonymous=True)

	rate = rospy.Rate(1) #1Hz

	while not rospy.is_shutdown():
		# Generate number:
		num = int_generator(1, 1000)

		# log the number:
		rospy.loginfo(str(num))

		# Publish the integer:
		pub.publish(str(num))

		rate.sleep()

if __name__ == "__main__":
	try:
		main()

	except rospy.ROSInterruptException:
		pass
