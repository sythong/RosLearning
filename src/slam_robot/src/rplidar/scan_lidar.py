#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan
import math
import numpy as np 


def scan_callback(scan_data):
    # find min value and min index
    min_value, min_index = getMinRangeIndex(scan_data.ranges)
    print("\nthe minimum range value is: ", min_value)
    print("the minimum range index is: ", min_index)

    # value at specific range
    range = getRangeIndex(0, scan_data.ranges)
    print("the range at index %f range index is: %f",0,  range )

def getRangeIndex(index, ranges):
    range = ranges[index]
    return range

def getMinRangeIndex(ranges):
    ranges = [x for x in ranges if not (math.isnan(x) or math.isinf(x))]
    return (min(ranges), ranges.index(min(ranges)))

if __name__ == '__main__':

    # init new a node and give it a name
    rospy.init_node('scan_lidar_node_py', anonymous=True)
    #subcribe to the topic /scan
    rospy.Subscriber("scan", LaserScan, scan_callback)

    # spin() simply keeps python from exiting until this node stoped
    rospy.spin()