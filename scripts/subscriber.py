#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16

integers = []

def is_prime(num):
	if num == 1:
		return False
	for i in range(2, int(num**0.5) + 1):
		if num % i == 0:
			return False
	return True

def num_to_print():
	max_num, min_num = max(integers), min(integers)
	if is_prime(min_num) and not is_prime(max_num):
		return min_num
	return max_num


def printer(data):
	integers.append(data.data)
	if len(integers) == 2:
		result = num_to_print()
		rospy.loginfo("The integer is: %d" %(result))
		del integers[:]



def subscriber():

	rospy.init_node('subscriber', anonymous=True)
	rospy.Subscriber('pub1', Int16, printer)
	rospy.Subscriber('pub2', Int16, printer)
	rospy.spin()

if __name__ == '__main__':
	subscriber()