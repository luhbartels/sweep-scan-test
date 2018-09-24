#! /usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan

def clb(msg):
	
	for i in range (0,6279):
		if msg.ranges[i] > 0 and msg.ranges[i] < 40:
			dist = msg.ranges[i]
			print ('Object detected ', dist, 'Angle ', i)
					


rospy.init_node('scan_values')
sub = rospy.Subscriber('/scan', LaserScan, clb)
rospy.spin()

