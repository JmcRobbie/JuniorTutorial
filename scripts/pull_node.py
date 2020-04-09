#!/usr/bin/env python
# Author: Peter Stulpner, pstulpner@student.unimelb.edu.au

import rospy
from std_msgs.msg import String

# Global variables:
node_1_num = 0
node_2_num = 0


def isprime(n):
	'''Function takes an integer n and returns True if prime and False otherwise '''

	# See if n is less than 2
	if n < 2:
		return False

	# See if n is divisible by 2
	if n % 2 == 0:
		return False

	for i in range(3, n, 2):
		if n % i == 0:
			return False

	return True

def callback_1(msg):
	global node_1_num
#	rospy.loginfo(msg.data)
	node_1_num = int(msg.data)


def callback_2(msg):
	global node_2_num
#	rospy.loginfo(msg.data)
	node_2_num = int(msg.data)

def main():
	'''Function creates the node which recieves the 2 integers '''

	global node_1_num
	global node_2_nun

	# Initialise the node:
	rospy.init_node("pull_node", anonymous=True)

	# Initialise a rate:
	rate = rospy.Rate(1) # 1Hz

	# Subscribe it to the other nodes:
	rospy.Subscriber("first_num", String, callback_1)
	rospy.Subscriber("second_num", String, callback_2)

	while not rospy.is_shutdown():
#		print "Node 1: {} Node 2: {}".format(node_1_num, node_2_num)
		both_prime = False
		small_prime = False

		# Find the smaller and larger number:
		small_num = node_1_num if node_1_num <= node_2_num else node_2_num
		large_num = node_1_num if small_num != node_1_num else node_2_num

		# Check to see if small is prime:
		if isprime(small_num):
			small_prime = True
			if isprime(large_num):
				both_prime = True

		# Print results:
		if small_prime and not both_prime:
			print "The smaller number is: {} and it is prime".format(small_num)

		elif isprime(large_num):
			print "The larger number is: {} and it is prime".format(large_num)
		else:
			print "The larger number is: {}".format(large_num)

		rate.sleep()

if __name__ == "__main__":
	main()
