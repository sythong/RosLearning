/*
 * scan_lidar_node.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: thongktdt
 */


#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "laserscan/LaserScanner.h"

using namespace std;

//sensor_msgs::LaserScan _scanMsg;
ros::Subscriber scanSubcriber;

void scanCallBack(sensor_msgs::LaserScan scanMessage);

int main(int argc, char ** argv){

	// Initialize the Ros node
	ros::init(argc, argv, "scan_lidar_node_cpp");
	ros::NodeHandle n;

	scanSubcriber = n.subscribe("/scan", 10, scanCallBack);

	ros::spin();
}

void scanCallBack(sensor_msgs::LaserScan scanMessage)
{
	//_scanMsg = scanMessage;
		cout<<"minimum range: " <<LaserScanner::getMinimumRange(scanMessage)<<endl;
	    cout<<"maximum range: " <<LaserScanner::getMaximumRange(scanMessage)<<endl;
	    cout<<"average range: " <<LaserScanner::getAverageRange(scanMessage,0,600)<<endl;
	    if (LaserScanner::isObstacleTooClose(scanMessage,0,600,0.2)==true){
	        cout<<"obstacle too close"<<endl;
	    }
	    cout<<endl;
}


