#!/usr/bin/env python
# Author: Peter Stulpner, pstulpner@student.unimelb.edu.au

import rospy
from std_msgs.msg import String
from sys import argv
from sys import exit

node_num = dict()

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

def callback(msg, arg):
	global node_num
#	rospy.loginfo(msg.data)
	message_data = int(msg.data)
	node_num["Node " + str(arg)] = message_data


def main():
	'''Function creates the node which recieves the 2 integers '''
	global node_num

	num_topic = 0

	# See how many topic need to subscribe to:
	try:
		num_topic = int(argv[1])

	except:
		print "Error no arguments supplied"
		exit(1)


	# Initialise the node:
	rospy.init_node("pull_node", anonymous=True)

	# Initialise a rate:
	rate = rospy.Rate(1) # 1Hz

	# Subscribe it to the other nodes:
	for i in range(0, num_topic):
		node_num["Node " + str(i + 1)] = 0
		rospy.Subscriber("num_" + str(i+1), String, callback, (i+ 1))

#	print "Number of topics: {}".format(num_topic)
#	print "Node num dictionary: {}".format(node_num)

	while not rospy.is_shutdown():
		both_prime = False
		small_prime = False

		# Find the smaller and larger number:
		small_num = min(node_num.values())
		large_num = max(node_num.values())

		# Check to see if small is prime:
		if isprime(small_num):
			small_prime = True
			if isprime(large_num):
				both_prime = True

		# Print results:
		print "Node Values: {}".format(node_num) 
		print " ------------ "
		print "The smallest and largest number are: {} {}".format(small_num, large_num) 
		if small_prime and not both_prime:
			print "The smaller number is: {} and it is prime".format(small_num)

		elif isprime(large_num):
			print "The larger number is: {} and it is prime".format(large_num)
		else:
			print "The larger number is: {}".format(large_num)

		print " ---------- "
		rate.sleep()

if __name__ == "__main__":
	main()
