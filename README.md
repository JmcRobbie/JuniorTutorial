# JuniorTutorial
Run the following commands:

$ roslaunch JuniorTutorial JuniorTutorial.launch

To see the logs:

$ rosrun rqt_console rqt_console



This is a ROS & Git introductory challenge for the interested Juniors to work their way through.

Before Juniors can begin work on the autonomous car we need to develop some basic skills with 
* ROS
* GIT
* C++ and python

This challenge aims to help you do that. 

The idea is that after doing this you will be able to contribute here: https://github.com/MURDriverless

### ROS intro

ROS is the Robot Operating System, and is the core _middleware_ that we will be using for the driverless car. Knowing how to use it is critical. 

ROS works on a publisher subscriber model that is built around a node type network. Nodes (which is where our code will run) can either subscribe (recieve messages from) or publish (push messages to) a topic. Other nodes can do the same and communication between nodes is achieved by this message passing mechanism. 

Look into the tutorials here http://wiki.ros.org/ROS/Tutorials

These should give you the info you need to get this challenge going.

### GIT 
Git is the defacto version control tool for developers all over the world. If you ever write code professionally in a collaborative environment you will encounter it. MUR Driverless uses it for collaboration and code management. 

### The challenge

(This project wont make much sense until youve done the tutorials)

You need to create 3 ROS nodes and have them publish random integers between 1 and 1000 to 2 different topics. 

The 3rd topic will subscribe to both of them and every loop iteration it will print the larger integer published by the two topics to console. 

If the *smaller* number is prime, it will publish that instead, if they are both prime it will publish the larger number instead.

After you have written a ros package you need to open a pull request on *this* repo. I recommend you start by forking this repo first.

### Getting HELP!

You may be unfamilar with a number of the problems posed here. Feel free to reach out to myself on slack or discord, but also check in with other autonomous juniors.


