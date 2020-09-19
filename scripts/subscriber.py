#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16

numbers = []


def isPrime(num):
	if num == 0:
		return False
	count = 0
	for i in range(2, num):
		if num % i == 0:
			count = count + 1;
	if count==0:
		return True
	return False

def num_to_print():
	min_num = min(numbers)
	max_num = max(numbers)
	if isPrime(min_num) and not isPrime(max_num):
		return min_num
	return max_num


def callback(data):
	numbers.append(data.data)
	if len(numbers) == 2:
		result = num_to_print()
		rospy.loginfo("The integer is : %d" %(result))
		del numbers[:]



def subscriber():

	rospy.init_node('subscriber', anonymous=True)
	rospy.Subscriber('pub', Int16, callback)
	rospy.Subscriber('pub1', Int16, callback)
	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	subscriber()